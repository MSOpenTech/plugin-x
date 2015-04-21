#pragma once

#include "app.g.h"
#include "OpenGLES.h"
#include "openglespage.xaml.h"

namespace cocos2d
{
    ref class App sealed
    {
    public:
        App();
        virtual void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ e) override;
        static Windows::UI::Core::CoreDispatcher^ GetDispatcher();
        static void SetDispatcher(Windows::UI::Core::CoreDispatcher^ dispatcher);

    private:
        OpenGLESPage^ mPage;
        OpenGLES mOpenGLES;
        static Windows::UI::Core::CoreDispatcher^ Dispatcher;
    };
}
