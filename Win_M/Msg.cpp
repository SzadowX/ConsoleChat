#include <iostream>
#include <string>
#include "Msg.h"
void Msg::getPrivate(std::string l, std::string r) { // ����� ���������
	if ((l == this->_login && r == this->_recipient) || (r == this->_login && l == this->_recipient)) { // ����� (�������� ������� ��������� � ��������)
		std::cout << this->_login << ": " << _msg << std::endl;
	}
}
void Msg::getGroup() { // ����� ���������
	if (_recipient == "all") { // ���������
		std::cout << this->_login << ": " << _msg << std::endl;
	}
}