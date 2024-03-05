#pragma once
#include "IUser.h"

class Users : virtual public IUser
{
public:
	Users(string login, string password);
protected:
	string _login;
	string _password;
};

class User : public Users
{
public:
	User(string name, string login, string password);
	void Show() override;
protected:
	string _name;
};