#include "pch.h"
#include "plugin.h"

#include <iostream>

using namespace concurrency;
using namespace Windows::Foundation::Collections;
using namespace Platform;
using namespace Windows::ApplicationModel::Store;
using namespace Windows::Storage;

using namespace winrtInterface;

#define PRODUCT_KEY "product"
#define PROXY_STORE_KEY "windows_store_proxy"

namespace microsoftiap {

	public ref class microsoftiap sealed : public IProtocolIAP {
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

        // TODO
        virtual void callFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params) {
            return;
        }

        // TODO
        virtual Platform::String^ callStringFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params) {
            return L"";
        }

        // TODO
        virtual int callIntFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params) {
            return 0;
        }

        // TODO
        virtual bool callBoolFuncWithParam(Platform::String^ funcName, Windows::Foundation::Collections::IVector<IPluginParam^>^ params) {
            return false;
        }

        // TODO
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
			if (product != nullptr && licensingInfo->ProductLicenses->HasKey(product)) {
				foundProduct = true;
				activeProduct = licensingInfo->ProductLicenses->Lookup(product)->IsActive;
			}
			if (product == nullptr) {
				OnPayResult(PayResultCodeEnum::kPayFail, "product key not found");
			}
			else if (foundProduct == false) {
				OnPayResult(PayResultCodeEnum::kPayFail, "product not found");
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
        void sendResult(Windows::Foundation::IAsyncOperation <Platform::String^> ^ asyncOp, Platform::String^ product) {
            auto purchaseTask = create_task(asyncOp);
            auto wrapperTask = create_task([purchaseTask]() {
                return purchaseTask;
            });
            wrapperTask.then([this, product](task<Platform::String^> t) {
                try {
                    Platform::String^ receipt = t.get();
                    LicenseInformation^ licenseInfo = getLicenseInformation();
                    if (licenseInfo->ProductLicenses->Lookup(product)->IsActive) {
                        OnPayResult(PayResultCodeEnum::kPaySuccess, receipt);
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

	private:
		void log(Platform::String^ msg) {
			if (debugMode) {
                std::wcout << msg->Data() << std::endl; // TODO should do real logging, and this doesn't seem to actually be output to console anyway
			}
		}

        // requests product purchase on correct thread
        void purchaseProduct(Platform::String^ product) {
            dispatcher->RunAsync(
                Windows::UI::Core::CoreDispatcherPriority::Normal,
                ref new Windows::UI::Core::DispatchedHandler([this, product]() {
                try {
                    Windows::Foundation::IAsyncOperation <Platform::String^>^ asyncOp = nullptr;
                    if (this->getDebugMode()) {
                        asyncOp = CurrentAppSimulator::RequestProductPurchaseAsync(product, true);
                    }
                    else {
                        asyncOp = CurrentApp::RequestProductPurchaseAsync(product, true);
                    }
                    this->sendResult(asyncOp, product);
                }
                catch (Exception^ e) {
                    // TODO do something with exception
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

	};
} // end namespace












