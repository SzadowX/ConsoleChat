#pragma once
#include "IChat.h"

class Users : virtual public IChat
{
public:
	Users(string login, string password, string name);
	void Show() override;
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
protected:
	string _login;
	string _password;
	string _name;
};

