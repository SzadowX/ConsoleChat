#pragma once
#include <iostream>
#include <string>
#include "iUser.h"

class User : virtual public iUser{
protected:
	std::string _login;
	int _pass;
public:
	User() = default;
	User(std::string login) : _login(login){};
	User(std::string login, int pass) : _login(login), _pass(pass){};

	void Show(){
		std::cout << _login << " " << _pass << std::endl;
	}

	bool AuthCheck(std::string l, int p){
		if(l == this->_login && p == this->_pass){
			return true;
		}
		else{
			return false;
		}
	}

	std::string userName(){
		return this->_login;
	}
};

class Msg : public User{
private:
	std::string _body;
public:
	Msg(std::string login, std::string body) : User(login), _body(body){}; 
	void Show(){
		std::cout << _login << ": " << _body << std::endl;
	}
};
