#include <iostream>
#include "Users.h"
using namespace std;

Users::Users(string login, string password) : 
	_login(login), 
	_password(password) {}

User::User(string name, string login, string password) : 
	_name(name), 
	Users(login, password) {}

void User::Show()
{
	cout << "User name: " << _name << endl;
	cout << "User login: " << _login << endl;
	cout << "User password: " << _password << endl;
}