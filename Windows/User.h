#pragma once
#include <iostream>
#include <string>
#include <algorithm> // для std::copy_n

// класс пользователя

class User{
protected:
	std::string _login{}; // логин
	std::string _pass{}; // пароль
	std::string _name{}; // имя
	bool _status{}; // статус online/offline
public:
	
	// конструкторы объекта пользователя
	
	User(){};
	User(std::string login) : _login(login){}; // для наследования логина в Msg
	User(std::string login, std::string pass, std::string name){
		_login = login;
		_pass = pass;
		_name = name;
		_status = false;
	};

	~User(){};
	
	// методы класса пользователя
	// геттеры и возврат данных

	void getUser(); // вывод логина и пароля и статуса	
	std::string getLogin(); // возврат логина
	std::string getPass(); // возврат пароля
	void setStatus(bool s); // изменение статуса
	bool getStatus(); // возврат статуса (системный)
	std::string statusInfo(); // возврат статуса (читабельный)
};
