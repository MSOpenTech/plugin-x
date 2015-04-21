
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
#include "FacebookAgent.h"

using namespace cocos2d::plugin;

class AgentManager;
 /** Get singleton of FacebookAgent */
FacebookAgent* FacebookAgent::getInstance(){
  return nullptr;
}
/** Destroy singleton of FacebookAgent */
void FacebookAgent::destroyInstance(){
      
}

/**
@brief log in
@param cb callback of login
*/
void FacebookAgent::login(FBCallback cb){
}

/**
@brief log in with specific permissions
@param permissoins different permissions splited by ','
@param cb callback of login
*/
void FacebookAgent::login(std::string& permissions, FBCallback cb){
      
}

/**
@brief log out
*/
void FacebookAgent::logout(){
}

/**
@brief Check whether the user logined or not
*/
bool FacebookAgent::isLoggedIn(){
  return false;
}
/**
@brief get UserID
**/
std::string FacebookAgent::getUserID(){
  return "";
}
/**
@brief get AccessToken
*/
std::string FacebookAgent::getAccessToken(){
  return "";
}

/**
@brief get permissoin list
*/
std::string FacebookAgent::getPermissionList(){
  return "";
}

/**
@brief share
@param info share information
@param cb callback of share
*/
void FacebookAgent::share(FBInfo &info, FBCallback cb){
}
/**
@brief open a dialog of Facebook app
@param info share information
@param cb callback of dialog
*/
void FacebookAgent::dialog(FBInfo &info, FBCallback cb){
}
bool FacebookAgent::canPresentDialogWithParams(FBInfo &info){
  return false;
}
void FacebookAgent::webDialog(FBInfo &info, FBCallback cb){
}

/**
@brief open the app request dialog of Facebook app
@param info share information
@param cb callback of dialog
*/
void FacebookAgent::appRequest(FBInfo &info, FBCallback cb){
}

/**
@brief use Facebook Open Graph api
@param path path of Open Graph api
@param method HttpMethod
@param params request parameters
@param cb callback of request
*/
void FacebookAgent::api(std::string &path, int method, FBInfo &params, FBCallback cb){
}

/**
@brief Notifies the events system that the app has launched & logs an activatedApp event.
*/
void FacebookAgent::activateApp(){
}

/**
@brief Log an app event with the specified name, supplied value, and set of parameters.
*/
void FacebookAgent::logEvent(std::string& eventName){

}

void FacebookAgent::logEvent(std::string& eventName, float valueToSum){

}

void FacebookAgent::logEvent(std::string& eventName, FBInfo& parameters){

}

void FacebookAgent::logEvent(std::string& eventName, float valueToSum, FBInfo& parameters){
      
}

/*
@breif Log an app event for purchase.
*/
void FacebookAgent::logPurchase(float mount, std::string currency){
      
}

void FacebookAgent::logPurchase(float mount, std::string currency, FBInfo &parmeters){
      
}
/*
@breif return the version of Facebook SDK for Cocos
*/
std::string FacebookAgent::getSDKVersion(){
  return "";
}

FacebookAgent::FBCallback FacebookAgent::getRequestCallback(int index){
  FBCallback fbcb;
  return fbcb;
}
FacebookAgent::FacebookAgent(){
      
}