#include <iostream>
#include <string>
#include "User.h"
void User::getUser() { // ����� ������ � ����� � �������
	std::cout << _login << "\t" << _name << "\t" << statusInfo() << std::endl;
}
std::string User::getLogin() { // ������� ������
	return this->_login;
}
std::string User::getPass() { // ������� ������
	return this->_pass;
}
void User::setStatus(bool s) { // ��������� �������
	this->_status = s;
}
bool User::getStatus() { // ������� ������� (���������)
	return _status;
}
std::string User::statusInfo() { // ������� ������� (�����������)
	if (_status == 0) {
		return std::string("�� � ����");
	}
	else {
		return std::string("� ����");
	}
}