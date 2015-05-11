#include "App.xaml.h"
#include "OpenGLESPage.xaml.h"

using namespace cocos2d;

Windows::UI::Core::CoreDispatcher^ App::Dispatcher = nullptr;

App::App()
{
    InitializeComponent();
}

Windows::UI::Core::CoreDispatcher^ App::GetDispatcher()
{
    return Dispatcher;
}

void App::SetDispatcher(Windows::UI::Core::CoreDispatcher^ dispatcher) 
{
    Dispatcher = dispatcher;
}

void App::OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ e)
{
    if (mPage == nullptr)
    {
        mPage = ref new OpenGLESPage(&mOpenGLES);
    }

    // Place the page in the current window and ensure that it is active.
    Windows::UI::Xaml::Window::Current->Content = mPage;
    Windows::UI::Xaml::Window::Current->Activate();
}
