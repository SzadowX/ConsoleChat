#include <iostream>
#include <string>
#include "user.h"

void User::Show(){
	std::cout << _login << " " << _pass << std::endl;
}

bool User::AuthCheck(std::string l, std::string p){
	if(l == this->_login && p == this->_pass){
		return true;
	}
	else{
		return false;
	}
}

std::string User::userName(){
	return this->_login;
}

void User::getUser(){
	std::cout << _login << std::endl;
	std::cout << _name << std::endl;
}

void User::setName(std::string n){
	this->_name = n;
}

void User::changePass(){}

void User::changeLogin(){}

void Chat::signIn(){}

void Chat::logIn(){}

void Chat::logOut(){}

void Msg::Show(){
	std::cout << _login << ": " << _body << std::endl;
}
