#pragma once
#include "IChat.h"

class Users : virtual public IChat
{
public:
	Users(string login, string password, string name);
	bool AuthCheck(string l, string p) {
		if (l == this->_login && p == this->_password) {
			return true;
		}
		else {
			return false;
		}
	}
protected:
	string _login;
	string _password;
	string _name;
};

class Chat : public Users
{
public:
	void SignIn();
	void LogIn();
	void LogOut();
	static bool isLogin;
};

