#include <iostream>
#include <string>
#include "User.h"

void User::getUser(){ // вывод логина и пароля и статуса
	std::cout << _login << " " << _pass << " " << statusInfo() << std::endl;
	showAllMsg();
}

void User::showAllMsg(){
	for(int i = 0; i < _msgcount; i++){
		_msglist1[i].showMsg();	
	}
}

void User::setStatus(bool s){ // вывод статуса
	this->_status = s;
}

std::string User::getLogin(){ // возврат логина
	return _login;
}

std::string User::getPass(){ // возврат пароля
	return _pass;
}
	
bool User::getStatus(){ // возврат статуса (системный)
	return _status;
}
	
std::string User::statusInfo(){ // возврат статуса (читабельный)
	if(_status == 0){
		return std::string("не в сети");
	}
	else{
		return std::string("в сети");
	}	
}

void User::logOut(){ // выход пользователя из чата
	_status = false;
}

void User::userTyping(){ // ввод сообщений
//	while(true){
		std::string msg_body;
		std::cout << _login << ": ";
		std::getline(std::cin, msg_body);

		if(msg_body == "quit"){
			std::cout << "Пользователь вышел из чата" << std::endl;
			logOut();
//			break;
		}	
		else{
		}
//	}
}

