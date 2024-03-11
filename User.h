#pragma once
#include <iostream>
#include <string>
#include <algorithm> // для std::copy_n
#include "Msg.h"

// класс пользователя

class User{
protected:
	std::string _login{}; // логин
	std::string _pass{}; // пароль
	std::string _name{}; // имя
	bool _status{}; // статус online/offline
	int _msgcount{1}; // счетчик сообщений
	Msg *_msglist1{}; // объект массива сообщений пользователя (доделать)
public:
	// конструкторы объекта пользователя
	User(){};
	User(std::string login) : _login(login){};
	User(std::string login, std::string pass) : _login(login), _pass(pass){};
//	User(std::string login, std::string pass, bool status) : _login(login), _pass(pass), _status{status}{};
	User(std::string login, std::string pass, bool status){
		_login = login;
		_pass = pass;
		_status = status;
		_msglist1 = new Msg[_msgcount]{}; // массив сообщений
		_msglist1[0] = Msg(_login, std::string("Welcome!"));	
	};
	
	// методы класса пользователя
	// геттеры и возврат данных

	void getUser(); // вывод логина и пароля и статуса	
	void setStatus(bool s); // вывод статуса
	std::string getLogin(); // возврат логина
	std::string getPass(); // возврат пароля
	bool getStatus(); // возврат статуса (системный)
	std::string statusInfo(); // возврат статуса (читабельный)
	
	// функции

	void logOut(); // выход пользователя из чата
	void userTyping(); // ввод сообщений (нужно доработать)

	void showAllMsg();
};
