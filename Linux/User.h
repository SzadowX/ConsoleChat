#pragma once
#include <iostream>
#include <string>
#include <algorithm> // для std::copy_n
//#include "Msg.h"

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
	User(std::string login, std::string pass){
		_login = login;
		_pass = pass;
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
	
	// функции для работы с пользователем

	void logOut(); // выход пользователя из чата
//	void userTyping(); // ввод сообщений (нужно доработать) (не актуально)

	// функции для работу с сообщенями
/*
	void saveMsg(int i, int r, std::string m);
	void syncMsg(int i);
	void resizeMsg(int newLength); // изменение размера объекта массива пользователей
*/
};
