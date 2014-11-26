#include "ProtocolUser.h"
using namespace cocos2d::plugin;

ProtocolUser::ProtocolUser(){

}
ProtocolUser::~ProtocolUser(){

}

/**
@brief config the application info
@param devInfo This parameter is the info of aplication,
different plugin have different format
@warning Must invoke this interface before other interfaces.
And invoked only once.
*/
void ProtocolUser::configDeveloperInfo(TUserDeveloperInfo devInfo){

}

/**
@brief User login
*/
void ProtocolUser::login(){

}
void ProtocolUser::login(ProtocolUserCallback &cb){

}

/**
@brief User logout
*/
void ProtocolUser::logout(){

}
void ProtocolUser::logout(ProtocolUserCallback &cb){

}

bool ProtocolUser::isLoggedIn(){
  return false;
}
/**
@brief Get session ID
@return If user logined, return value is session ID;
else return value is empty string.
*/
std::string ProtocolUser::getSessionID(){
  return "";
}

/**
@brief get Access Token
*/
std::string ProtocolUser::getAccessToken(){
  return "";
}