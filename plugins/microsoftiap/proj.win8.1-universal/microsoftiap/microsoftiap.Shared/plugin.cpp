#include "pch.h"
#include "plugin.h"

#include <iostream>

using namespace concurrency;
using namespace Windows::Foundation::Collections;
using namespace Platform;
using namespace Windows::ApplicationModel::Store;
using namespace Windows::Storage;

using namespace winrtInterface;

#define TESTING 

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
			// The path looked up by "windows_store_proxy" must use \ to split directories and not /
#ifdef TESTING
			loadWindowsStoreProxyFile(devInfo->Lookup("windows_store_proxy"));
#endif
		}

        // checks that the product can in fact be purchased before attempting to buy
		virtual void payForProduct(IMap<Platform::String^, Platform::String^>^ info) {
			Platform::String^ product = nullptr;
			bool foundProduct = false;
			bool activeProduct;
			LicenseInformation^ licensingInfo = getLicenseInformation();
			if (info->HasKey("product")) {
				product = info->Lookup("product");
			}
			if (product != nullptr && licensingInfo->ProductLicenses->HasKey(product)) {
				foundProduct = true;
				activeProduct = licensingInfo->ProductLicenses->Lookup(product)->IsActive;
			}
			if (product == nullptr) {
				sendPayResult(PayResultCodeEnum::kPayFail, "product key not found");
			}
			else if (foundProduct == false) {
				sendPayResult(PayResultCodeEnum::kPayFail, "product not found");
			}
			else if (activeProduct == true) {
				sendPayResult(PayResultCodeEnum::kPayFail, "product already purchased");
			}
			else {
				log("purchasing product");
				purchaseProduct(product);
			}
		}

        // send payment result to cocos app
		void sendPayResult(PayResultCodeEnum ret, Platform::String^ msg) {
            log(msg);
            log("calling listener");
            OnPayResult(ret, msg);
		}

        void loadWindowsStoreProxyFile(Platform::String^ filePath) {
            StorageFolder^ installationFolder = Windows::ApplicationModel::Package::Current->InstalledLocation;
            create_task(installationFolder->GetFileAsync(filePath)).then([this](task<StorageFile^> currentTask) {
                StorageFile^ file;
                try {
                    file = currentTask.get();
                    create_task(CurrentAppSimulator::ReloadSimulatorAsync(file)).then([this] {
                    }).wait();
                }
                catch (Platform::Exception^ e) {
                    OutputDebugString(e->Message->Data());
                }
            }).wait();
        }

        // waits on async action
        void sendResult(Windows::Foundation::IAsyncOperation <Platform::String^> ^ action, Platform::String^ product) {
            try {
                create_task(action).then([this, product](Platform::String^ msg) {
                    LicenseInformation^ licenseInfo = this->getLicenseInformation();
                    if (licenseInfo->ProductLicenses->Lookup(product)->IsActive) {
                        sendPayResult(PayResultCodeEnum::kPaySuccess, msg); // TODO what should the msg be?
                    }
                    else {
                        sendPayResult(PayResultCodeEnum::kPayFail, "product was not purchased");
                    }
                });
            }
            catch (Exception^ e) {
                // TODO do something with exception
                this->sendPayResult(PayResultCodeEnum::kPayFail, "product was not purchased");
            }
        }

		LicenseInformation^ getLicenseInformation() {
#ifdef TESTING
			return CurrentAppSimulator::LicenseInformation;
#else
			return CurrentApp::LicenseInformation;
#endif
		}

        virtual void setDispatcher(Windows::UI::Core::CoreDispatcher^ dispatcher) {
            this->dispatcher = dispatcher;
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
                    auto ret = CurrentAppSimulator::RequestProductPurchaseAsync(product, true);
                    this->sendResult(ret, product);
                }
                catch (Exception^ e) {
                    // TODO do something with exception
                    this->sendPayResult(PayResultCodeEnum::kPayFail, "product was not purchased");
                }
            }));

        }

	};
} // end namespace












