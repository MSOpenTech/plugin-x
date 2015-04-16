
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

#include "ProtocolShare.h"
#include "PluginMap.h"
#include "util.h"

using namespace cocos2d::plugin;

ProtocolShare::ProtocolShare() {
    _listener = nullptr;
    _callback = nullptr;
}

ProtocolShare::~ProtocolShare() {
    PluginMap::mapIProtocol.erase(this);
    PluginMap::mapIProtocolShare.erase(this);
}

  /**
  @brief config the share developer info
  @param devInfo This parameter is the info of developer,
  different plugin have different format
  @warning Must invoke this interface before other interfaces.
  And invoked only once.
  */
void ProtocolShare::configDeveloperInfo(TShareDeveloperInfo devInfo) {

}

  /**
  @brief share information
  @param info The info of share, contains key:
  SharedText                	The text need to share
  SharedImagePath				The full path of image file need to share (optinal)
  @warning For different plugin, the parameter should have other keys to share.
  Look at the manual of plugins.
  */
void ProtocolShare::share(TShareInfo info) {
    PluginMap::mapIProtocolShare[this]->share(pluginx::util::stdStrMapToPlatformStrMap(&info));
}

void ProtocolShare::share(TShareInfo &info, ProtocolShareCallback &cb) {
    _callback = cb;
    share(info);
}

  /**
  @deprecated
  @breif set the result listener
  @param pListener The callback object for share result
  @wraning Must invoke this interface before share
  */
CC_DEPRECATED_ATTRIBUTE void ProtocolShare::setResultListener(ShareResultListener* pListener) {
    _listener = pListener;
}

  /**
  @deprecated
  @breif get the result listener
  @return The callback object for share result
  @wraning Must invoke this interface before share
  */
CC_DEPRECATED_ATTRIBUTE ShareResultListener* ProtocolShare::getResultListener() {
  return _listener;
}

  /**
  @brief share result callback
  */
void ProtocolShare::onShareResult(ShareResultCode ret, const char* msg) {
    if (_listener != nullptr) {
        _listener->onShareResult(ret, msg);
    }
    if (_callback != nullptr) {
        std::string message(msg);
        _callback(ret, message);
    }
}