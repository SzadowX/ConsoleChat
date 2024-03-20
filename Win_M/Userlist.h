#pragma once
#include <iostream>
#include <string>
#include <algorithm> // ��� std::copy_n
#include "User.h"
#include "Msg.h"
// ����� ������ �������������
class UserList {
private:
	int _length{};
	User* _userlist{};
	int _count{};
	Msg* _msglist{};
public:
	/* ����������� ������� ������������� ������� ������ ������������� */
	UserList(int length, int count) : _length(length), _count(count) {
		_userlist = new User[_length]{}; // ������ ��������������
		_userlist[0] = User(std::string("admin"), std::string("admin"), std::string("�����")); // �������� ������ ������������ (������)
		_msglist = new Msg[_count]{}; // ������ ���������
		_msglist[0] = Msg(_userlist[0].getLogin(), std::string("Welcome!")); // ����������� �� ������
	}
	~UserList() {
		delete[] _userlist;
		delete[] _msglist;
	}
	/* ������ ������ ������ �������������� */
	/* ������������ */
	bool authCheck(std::string l, std::string p);
	int getIndex(std::string l); // ������� ������� ������������ �� ������
	void setUser(); // �������� ������ ������������
	void logIn(); // ���� ������������ � �������
	void logOut(int n); // ����� ������������ �� ����
	void userTyping(int i, int j); //  ���� ����� ��������� 
	/* ������ ������������� */
	void resize(int newLength); // ��������� ������� ������� ������� �������������
	void showUsers(); // ����� ������ �������������
	int getLength(); // ������� ���������� ������������� (����� ������� �������)
	/* ��������� */
	void saveMsg(int _i, int _ir, std::string _m);
	void getMsgs(int _i, int _ir);
	void resizeMsgList(int newCount); // ��������� ������� ������� ������� ���������
};