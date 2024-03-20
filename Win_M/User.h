#pragma once
#include <iostream>
#include <string>
#include <algorithm> // ��� std::copy_n
class User {// ����� ������������
protected:
	std::string _login{}; // �����
	std::string _pass{}; // ������
	std::string _name{}; // ���
	bool _status{}; // ������ online/offline
public:
	// ������������ ������� ������������
	User() {};
	User(std::string login) : _login(login) {}; // ��� ������������ ������ � Msg
	User(std::string login, std::string pass, std::string name) {
		_login = login;
		_pass = pass;
		_name = name;
		_status = false;
	};
	~User() {};
	// ������ ������ ������������
	void getUser(); // ����� ������ � ������ � �������	
	std::string getLogin(); // ������� ������
	std::string getPass(); // ������� ������
	void setStatus(bool s); // ��������� �������
	bool getStatus(); // ������� ������� (���������)
	std::string statusInfo(); // ������� ������� (�����������)
};