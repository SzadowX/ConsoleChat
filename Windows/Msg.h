#pragma once
#include <iostream>
#include <string>
#include "User.h"

/* класс сообщений */

class Msg : public User{
private:
	std::string _recipient; // адресат
	std::string _msg; // сообщение
public:
	Msg(){};
	Msg(std::string login, std::string msg) : User(login), _msg(msg){};
	Msg(std::string login, std::string recipient, std::string msg) : User(login), _recipient(recipient), _msg(msg){};
	~Msg(){};
	
	void getPrivate(std::string l, std::string r); // вывод личных сообщений
	void getGroup(); // вывод групповых сообщений
};