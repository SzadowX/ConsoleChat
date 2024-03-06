#pragma once
#include <iostream>
#include <string>
#include "iUser.h"

class User : virtual public iUser{
protected:
	std::string _login;
	std::string _pass;
	std::string _name;
public:
	User() = default;
	User(std::string login) : _login(login){};
	User(std::string login, std::string pass) : _login(login), _pass(pass){};
	User(std::string login, std::string pass, std::string name) : _login(login), _pass(pass), _name(name){};

	void Show(); // вывод логина и пароля +
	bool AuthCheck(std::string l, std::string p); // проверка логина и пароля при входе +
	std::string userName(); // возвращает логин +
	void getUser(); // вывод логина и имени -
	void setName(std::string n); // добавление или изменение имени -
	void changePass(); // изменение пароля -
	void changeLogin(); // изменение логина -
};

class Chat : public User{
private:
public:
	void signIn(); // регистрация -
	void logIn(); // вход -
	void logOut(); // выход -
};

class Msg : public User{
private:
	std::string _body; // тело сообщения
public:
	Msg(std::string login, std::string body) : User(login), _body(body){}; 
	void Show(); // вывод пары автор:сообщение 
};
