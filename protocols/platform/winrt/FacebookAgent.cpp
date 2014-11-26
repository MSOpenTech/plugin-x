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