#include "ProtocolShare.h"
using namespace cocos2d::plugin;

ProtocolShare::ProtocolShare(){

}

ProtocolShare::~ProtocolShare(){

}



  /**
  @brief config the share developer info
  @param devInfo This parameter is the info of developer,
  different plugin have different format
  @warning Must invoke this interface before other interfaces.
  And invoked only once.
  */
void ProtocolShare::configDeveloperInfo(TShareDeveloperInfo devInfo){

}

  /**
  @brief share information
  @param info The info of share, contains key:
  SharedText                	The text need to share
  SharedImagePath				The full path of image file need to share (optinal)
  @warning For different plugin, the parameter should have other keys to share.
  Look at the manual of plugins.
  */
void ProtocolShare::share(TShareInfo info){

}
void ProtocolShare::share(TShareInfo &info, ProtocolShareCallback &cb){

}

  /**
  @deprecated
  @breif set the result listener
  @param pListener The callback object for share result
  @wraning Must invoke this interface before share
  */
CC_DEPRECATED_ATTRIBUTE void ProtocolShare::setResultListener(ShareResultListener* pListener){

}

  /**
  @deprecated
  @breif get the result listener
  @return The callback object for share result
  @wraning Must invoke this interface before share
  */
CC_DEPRECATED_ATTRIBUTE ShareResultListener* ProtocolShare::getResultListener(){
  return nullptr;
}

  /**
  @brief share result callback
  */
void ProtocolShare::onShareResult(ShareResultCode ret, const char* msg){

}