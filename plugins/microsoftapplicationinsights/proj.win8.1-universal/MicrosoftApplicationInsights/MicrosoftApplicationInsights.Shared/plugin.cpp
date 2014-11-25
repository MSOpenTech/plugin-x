#include "pch.h"
using namespace Platform;
using namespace winrtInterface;
using namespace Windows::Foundation::Collections;
using namespace Platform::Collections;
using namespace Microsoft::ApplicationInsights::Telemetry::WindowsStore;
#include <unordered_map>
using namespace std;
namespace MicrosoftApplicationInsights
{
  public ref class MicrosoftApplicationInsights sealed : public IProtocolAnalytics, IProtocol
  {
    private:
      unordered_map<String^, TimedAnalyticsEvent ^>timedEvents;
    public :
    /**
    @brief plug-in info methods(name, version, SDK version)
    */
    virtual Platform::String^ getPluginVersion(){
      return L"0.0.0";
    }
    virtual Platform::String^ getSDKVersion(){
      return L"0.0.0";
    }
    /**
    @brief switch debug plug-in on/off
    */
    virtual void setDebugMode(bool bDebug){
    }
    /**
    @brief Start a new session.
    @param appKey The identity of the application.
    */
    virtual void startSession(Platform::String^ appKey){
      OutputDebugString(appKey->Data());
		  ClientAnalyticsSession::Default->Start(appKey);
      ClientAnalyticsSession::Default->Enabled = true;
    }

    /**
    @brief Stop a session.
    @warning This interface only worked on android
    */
    virtual void stopSession(){
      ClientAnalyticsSession::Default->Enabled = false;
    }

    /**
    @brief Set the timeout for expiring a session.
    @param millis In milliseconds as the unit of time.
    @note It must be invoked before calling startSession.
    */
    virtual void setSessionContinueMillis(int millis){
    }

    /**
    @brief log an error
    @param errorId The identity of error
    @param message Extern message for the error
    */
    virtual void logError(Platform::String^ errorId, Platform::String^ message){
      Map<String^, Object^> ^properties = ref new Map<String^, Object^>;
      properties->Insert(L"Message",  message);
		  ClientAnalyticsChannel::Default->LogEvent(errorId, properties);
    }

    /**
    @brief log an event.
    @param eventId The identity of event
    @param paramMap Extern parameters of the event, use NULL if not needed.
    */
    virtual void logEvent(Platform::String^ eventId, Windows::Foundation::Collections::IMap<Platform::String^, Platform::String^> ^paramMap){
      Map<String^, Object^> ^properties = ref new Map<String^, Object^>;
      if (paramMap)
      {
        for (auto p = paramMap->First(); p->HasCurrent; p->MoveNext())
        {
          properties->Insert(p->Current->Key, p->Current->Value);
        }
        ClientAnalyticsChannel::Default->LogEvent(eventId, properties);
      }
      else
      {
        ClientAnalyticsChannel::Default->LogEvent(eventId, nullptr);
      }
    }

    /**
    @brief Track an event begin.
    @param eventId The identity of event
    */
    virtual void logTimedEventBegin(Platform::String^ eventId){
      if (timedEvents.count(eventId))timedEvents[eventId]->Cancel();
      timedEvents[eventId] = ClientAnalyticsChannel::Default->StartTimedEvent(eventId);
    }

    /**
    @brief Track an event end.
    @param eventId The identity of event
    */
    virtual void logTimedEventEnd(Platform::String^ eventId){
      if (timedEvents.count(eventId)){
        timedEvents[eventId]->End();
        timedEvents.erase(eventId);
      }
    }

    /**
    @brief Whether to catch uncaught exceptions to server.
    @warning This interface only worked on android.
    */
    virtual void setCaptureUncaughtException(bool enabled){

    }
  };
}



