
/****************************************************************************
Copyright (c) 2012-2013 cocos2d-x.org
Copyright (c) Microsoft Open Technologies, Inc.
Copyright (c) Microsoft Corporation.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "pch.h"
#include "plugin.h"

#include <set>
#include <iostream>

using namespace concurrency;
using namespace Windows::Foundation::Collections;
using namespace Platform;
using namespace Windows::ApplicationModel::Store;
using namespace Windows::Storage;
using namespace Microsoft::WRL;

using namespace cocosPluginWinrtBridge;


#define PRODUCT_KEY "product"
#define PROXY_STORE_KEY "windows_store_proxy"

namespace microsoftiap {

    [Windows::Foundation::Metadata::WebHostHidden]
    public ref class microsoftiap sealed : public cocosPluginWinrtBridge::IProtocolIAP{
	private:
		bool debugMode;
        Windows::UI::Core::CoreDispatcher^ dispatcher;

	public:
        virtual event OnPayResultHandler^ OnPayResult;

		microsoftiap() {
			debugMode = false;
            dispatcher = nullptr;
		}

		/**
		@brief plug-in info methods(name, version, SDK version)
		*/
		virtual Platform::String^ getPluginVersion() {
			return L"0.0.0";
		}

		virtual Platform::String^ getSDKVersion() {
			return L"0.0.0";
		}

		/**
		@brief switch debug plug-in on/off
		*/
		virtual void setDebugMode(bool bDebug) {
			debugMode = bDebug;
		}

        virtual void callFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params) {
            return;
        }

        virtual Platform::String^ callStringFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params) {
            if (funcName == L"getEntitledDurables") {
                return getEntitledDurables();
            }
            if (funcName == L"getUnfulfilledConsumables") {
                return fetchUnfulfilledConsumables();
            }
            return L"";

        }

        virtual int callIntFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params) {
            return 0;
        }

        virtual bool callBoolFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params) {
            if (funcName == L"isProductPurchased") {
                Platform::String^ productName = params->GetAt(0)->getStringValue();
                return isProductPurchased(productName);
            }
            if (funcName == "reportConsumableFulfillment") {
                // params[0] : productId string
                // params[1] : transactionId string
                return reportFulfilledConsumable(params->GetAt(0)->getStringValue(), params->GetAt(1)->getStringValue()) == FulfillmentResult::Succeeded;
            }
            return false;
        }

        virtual float callFloatFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params) {
            return 0;
        }

		virtual void configDeveloperInfo(IMap<Platform::String^, Platform::String^>^ devInfo) {
			log("configuring developer info");
			// The path looked up by PROXY_STORE_KEY must use \ to split directories and not /
            if (debugMode) {
                loadWindowsStoreProxyFile(devInfo->Lookup(PROXY_STORE_KEY)); // TODO how should this fail if key isn't found?
            }
		}

        // checks that the product can in fact be purchased before attempting to buy
		virtual void payForProduct(IMap<Platform::String^, Platform::String^>^ info) {
			Platform::String^ product = nullptr;
			bool foundProduct = false;
			bool activeProduct;
			LicenseInformation^ licensingInfo = getLicenseInformation();
			if (info->HasKey(PRODUCT_KEY)) {
				product = info->Lookup(PRODUCT_KEY);
			}
            activeProduct = licensingInfo->ProductLicenses->Lookup(product)->IsActive;
			if (product == nullptr) {
				OnPayResult(PayResultCodeEnum::kPayFail, "product key not found");
			}
			else if (activeProduct == true) {
				OnPayResult(PayResultCodeEnum::kPayFail, "product already purchased");
			}
			else {
				log("purchasing product");
				purchaseProduct(product);
			}
		}

        // waits on async action, then sends result to cocos app
        void sendResult(Windows::Foundation::IAsyncOperation <PurchaseResults^> ^ asyncOp, Platform::String^ product) {
            auto purchaseTask = create_task(asyncOp);
            auto wrapperTask = create_task([purchaseTask]() {
                return purchaseTask;
            });
            wrapperTask.then([this, product](task<PurchaseResults^> t) {
                try {
                    PurchaseResults^ purchaseResults = t.get();
                    if (purchaseResults->Status == ProductPurchaseStatus::Succeeded) {
                        OnPayResult(PayResultCodeEnum::kPaySuccess, purchaseResults->ReceiptXml);
                    }
                    else {
                        OnPayResult(PayResultCodeEnum::kPayFail, "product was not purchased");
                    }
                }
                catch (Exception^ e) {
                    OnPayResult(PayResultCodeEnum::kPayFail, "product was not purchased");
                }
            });
        }

		LicenseInformation^ getLicenseInformation() {
            if (debugMode) {
                return CurrentAppSimulator::LicenseInformation;
            }
            else {
                return CurrentApp::LicenseInformation;
            }
		}

        virtual void setDispatcher(Windows::UI::Core::CoreDispatcher^ dispatcher) {
            this->dispatcher = dispatcher;
        }

        bool getDebugMode() {
            return debugMode;
        }

        bool isProductPurchased(Platform::String^ productName) {
            LicenseInformation^ licenseInfo = getLicenseInformation();
            if (licenseInfo->ProductLicenses->HasKey(productName)) {
                return getLicenseInformation()->ProductLicenses->Lookup(productName)->IsActive;
            }
            return false;
        }

	private:
		void log(Platform::String^ msg) {
			if (debugMode) {
                OutputDebugString(msg->Data());
			}
		}

        // requests product purchase on correct thread
        void purchaseProduct(Platform::String^ product) {
            dispatcher->RunAsync(
                Windows::UI::Core::CoreDispatcherPriority::Normal,
                ref new Windows::UI::Core::DispatchedHandler([this, product]() {
                try {
                    Windows::Foundation::IAsyncOperation<PurchaseResults^>^ asyncOp = nullptr;
                    if (this->getDebugMode()) {
                        asyncOp = CurrentAppSimulator::RequestProductPurchaseAsync(product);
                    }
                    else {
                        asyncOp = CurrentApp::RequestProductPurchaseAsync(product);
                    }
                    this->sendResult(asyncOp, product);
                }
                catch (Exception^ e) {
                    this->OnPayResult(PayResultCodeEnum::kPayFail, "product was not purchased");
                }
            }));

        }

        void loadWindowsStoreProxyFile(Platform::String^ filePath) {
            StorageFolder^ installationFolder = Windows::ApplicationModel::Package::Current->InstalledLocation;
            create_task(installationFolder->GetFileAsync(filePath)).then([this](task<StorageFile^> currentTask) {
                StorageFile^ storeProxyFile;
                try {
                    storeProxyFile = currentTask.get();
                    create_task(CurrentAppSimulator::ReloadSimulatorAsync(storeProxyFile)).then([this] {
                    }).wait();
                }
                catch (Platform::Exception^ e) {
                    OutputDebugString(e->Message->Data());
                }
            }).wait();
        }

        FulfillmentResult reportFulfilledConsumable(Platform::String^ productId, Platform::String^ transactionId) {
            GUID guid;
            HRESULT hresult = CLSIDFromString((LPWSTR)transactionId->Data(), (LPCLSID)&guid);
            Platform::Guid transactionIdGuid = Guid(guid);
            Windows::Foundation::IAsyncOperation<FulfillmentResult>^ asyncOp = nullptr;
            Windows::Foundation::IAsyncAction^ asyncAction = dispatcher->RunAsync(
                Windows::UI::Core::CoreDispatcherPriority::Normal,
                ref new Windows::UI::Core::DispatchedHandler([this, &asyncOp, &productId, &transactionIdGuid]() {
                    if (debugMode) {
                        asyncOp = CurrentAppSimulator::ReportConsumableFulfillmentAsync(productId, transactionIdGuid);
                    }
                    else {
                        asyncOp = CurrentApp::ReportConsumableFulfillmentAsync(productId, transactionIdGuid);
                    }
                }
            ));
            FulfillmentResult* result = new FulfillmentResult;
            create_task(asyncAction).wait();
            create_task(asyncOp).then([&result](FulfillmentResult r) {
                *result = r;
            }).wait();
            FulfillmentResult ret = *result;
            delete result;
            return ret;
        }

        IVectorView<UnfulfilledConsumable^>^ unfulfilledConsumables() {
            Windows::Foundation::IAsyncOperation<IVectorView<UnfulfilledConsumable^>^>^ asyncOp = nullptr;
            Windows::Foundation::IAsyncAction^ asyncAction = dispatcher->RunAsync(
                Windows::UI::Core::CoreDispatcherPriority::Normal,
                ref new Windows::UI::Core::DispatchedHandler([this, &asyncOp]() {
                    if (debugMode) {
                        asyncOp = CurrentAppSimulator::GetUnfulfilledConsumablesAsync();
                    }
                    else {
                        asyncOp = CurrentApp::GetUnfulfilledConsumablesAsync();
                    }
                }
            ));
            create_task(asyncAction).wait();
            IVectorView<UnfulfilledConsumable^>^ consumables = nullptr;
            create_task(asyncOp).then([&consumables](IVectorView<UnfulfilledConsumable^>^ result) {
                consumables = result;
            }).wait();
            return consumables;
        }
        
        Platform::String^ fetchUnfulfilledConsumables() {
            IVectorView<UnfulfilledConsumable^>^ consumables = unfulfilledConsumables();
            UnfulfilledConsumable^ c;
            Platform::String^ xmlString = L"<?xml version=\"1.0\" encoding=\"utf-8\"?><unfulfilled_consumables>";
            for (unsigned int i = 0; i < consumables->Size; ++i) {
                c = consumables->GetAt(i);
                xmlString += L"<consumable product_id=\"" + c->ProductId + L"\" transaction_id=\"" + c->TransactionId + L"\" />";
            }
            return xmlString;
        }

        Platform::String^ getEntitledDurables() {
            std::set<Platform::String^> consumableIds;
            IVectorView<UnfulfilledConsumable^>^ consumables = unfulfilledConsumables();
            for (unsigned int i = 0; i < consumables->Size; ++i) {
                consumableIds.insert(consumables->GetAt(i)->ProductId);
            }
            typedef Windows::Foundation::Collections::IKeyValuePair<Platform::String^, ProductLicense^>  T_item;

            LicenseInformation^ licenseInformation = getLicenseInformation();
            Windows::Foundation::Collections::IIterator< T_item ^>^ it = (Windows::Foundation::Collections::IIterator< T_item ^>^)licenseInformation->ProductLicenses->First();
            Platform::String^ xmlString = L"<?xml version=\"1.0\" encoding=\"utf-8\"?><product_ids>";
            while (it->HasCurrent)
            {
                T_item^ item = (T_item^)it->Current;
                if (!consumableIds.count(item->Key) && item->Value->IsActive) {
                    Platform::String^ key = item->Key;
                    xmlString += L"<product_id>" + key + L"</product_id>";
                }
                it->MoveNext();
            }
            xmlString += L"</product_ids>";
            return xmlString;
        }

	};
} // end namespace












