#include <iostream>
#include <string>
#include "Msg.h"


void Msg::getPrivate(std::string l, std::string r){ // вывод сообщений
	if((l == this->_login && r == this->_recipient) || (r == this->_login && l == this->_recipient)){ // личка (проверка логинов адресанта и адресата)
		std::cout << this->_login << ": " <<  _msg << std::endl;
	}
}

void Msg::getGroup(){ // вывод сообщений
	if(_recipient == "all"){ // групповые
		std::cout << this->_login<< ": " <<  _msg << std::endl;
	}
}
