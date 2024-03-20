#include <iostream>
#include <string>
#include <algorithm> // ��� std::copy_n
#include "Userlist.h"
/* ������������ */
bool UserList::authCheck(std::string l, std::string p) { // �������� ������ � ������ - ����������� ������������
	for (int i = 0; i < _length; i++)
		if (l == _userlist[i].getLogin()) {
			if (p == _userlist[i].getPass()) {
				std::cout << "----- ������������ " << l << " ����� � ���!\n" << std::endl;
				_userlist[i].setStatus(true);
				return true;
			}
			std::cout << "----- �������� ����� ��� ������!\n" << std::endl;
			return false;
		}
	std::cout << "----- �������� ����� ��� ������!\n" << std::endl;
	return false;
}
int UserList::getIndex(std::string l) { // ����� ������� ������������ �� �����
	for (int i = 0; i < _length; i++) {
		if (l == _userlist[i].getLogin()) {
			return i;
		}
	}
	std::cout << "----- ������������ �� ������!\n" << std::endl;
	return -1;
}
void UserList::setUser() { // �������� ������ ������������
	system("cls");//������� �����
	std::cout << "---------- ����������� ������ ������������ ----------\n[q]uit ��� ������\n����� � ������ �� ������ ��������� ��������\n";
	while (true) {
		bool available{ false }; // ����������� ������
		std::cout << "\n������� �����: ";
		std::string _l{}, _p{}, _n{}; // ���������� ��� ����� ������ � ������
		std::cin >> _l;
		std::cin.ignore(256, '\n'); // �������������� ����� ����� �������

		if (_l == "q") { // ������ ������
			std::cout << "----- ������!\n" << std::endl;
			break;
		}

		/* �������� ������� ������ � ������� */

		for (int i = 0; i < _length; i++) {
			if (_l == _userlist[i].getLogin()) {
				std::cout << "----- ����� �����, �������� ������ �����!\n" << std::endl;
				available = false;
				break;
			}
			else {
				available = true;
			}
		}
		if (available) {
			std::cout << "������� ������:  ";
			std::cin >> _p;
			std::cin.ignore(256, '\n'); // ������������� ����� �������� ����� �������

			std::cout << "������� ��� ������������: ";
			std::getline(std::cin, _n); // ����
            std::cout << "----- ������������ " << _n << " ���������������\n" << std::endl;
			resize(_length + 1); // ���������� ������� �������������
			_userlist[_length - 1] = User(_l, _p, _n); // �������� ������ ������� ������������ 
			break;
		}
	}
}
void UserList::logIn() { // ���� ������������ � �������
	/* ���� ������������ */
	system("cls");//������� �����
	int attempts = 3; // ���������� ������� �����(� ������ ������ 3)
	std::string _l{}, _p{};
	int i{};
	std::cout << "---------- ����������� ----------\n";
	while (attempts > 0) {
		std::cout << "� ��� �������� " << attempts << " ������� (��� ������ ������� q)\n";
		std::cout << "�����: ";
		std::cin >> _l;
		std::cin.ignore(256, '\n'); // ������������� ���� ����� �������
		if (_l == "q") { // ������ ������
			system("cls");//������� �����
			std::cout << "----- ������ �����������\n" << std::endl;
			attempts = -1; // ����� �� ����� ��� ������ �����������
			break;
		}
		std::cout << "������: ";
		std::cin >> _p;
		std::cin.ignore(256, '\n'); // ������������� ���� ����� �������
		if (authCheck(_l, _p)) {
			attempts = -1; // ����� �� ����� ��� �������� �����������
			i = getIndex(_l);
			    system("cls");//������� �����
		}
		else {
			attempts--; // ���������� ���-�� ������� ��� ������ � ������ ��� ������
		}
	}
	if (attempts == 0) { // ������ �����������
		std::cout << "----- �������� ����� �������!\n" << std::endl;
	}
	/* ������� � ������ ������ */
	while (_userlist[i].getStatus()) {
		std::cout << "������� ��� �����������:\n----------\nall\t(����� ������)\n";
		showUsers(); // ������ �������� (�������������)
		std::cout << "----------\n";
		std::cout << _l << ": "; // ��� �����������
		std::string c;
		std::cin >> c; // ��� ����������
		std::cin.ignore(); // ������������� ������� ����� cin, ����� getline �� �������� ������ ��������
		int ir; // ������ ����������
		if (c == "q") { // ����� �� ����� (������������ �� �������)
			system("cls");//������� �����
			logOut(i); // ����� ������ ������������
			std::cout << "----- ������������ ����� �� ����!\n" << std::endl;
		}
		else if (c == "all") { // ������� � ��������� ���
			    system("cls");//������� �����
			ir = -1;
			std::cout << "---------- ����� ������ ----------" << std::endl;
			getMsgs(i, ir);
			userTyping(i, ir);
		}
		else { // ������� � ��
			    system("cls");//������� �����
			ir = getIndex(c); // ������ ����������
			if (ir >= 0) {
				if (i == ir) {
					std::cout << "---------- ����������� ��������� ----------" << std::endl;
				}
				else {
					std::cout << "---------- ����������  " << _userlist[ir].getLogin() << " ----------" << std::endl;
				}
				getMsgs(i, ir);
				userTyping(i, ir);
			}
		}
	}
}
void UserList::logOut(int n) { // ����� ������������ �� ����
	_userlist[n].setStatus(false);
}
void UserList::userTyping(int i, int j) { // ���� ����� ���������
	while (_userlist[i].getStatus()) {
		std::string msg_body; // ���� ���������
		std::cout << _userlist[i].getLogin() << ": "; // ��� �����������
		std::getline(std::cin, msg_body); // ����

		if (msg_body == "q") { // ����� �� ����� (�������)
			    system("cls");//������� �����
			std::cout << "----- ������������ ����� �� �������!\n" << std::endl;
			break;
		}
		else {
			saveMsg(i, j, msg_body); // ���������� ���������:��������:��������� (�����)
		}
	}
}
/* ������ ������������� */
void UserList::resize(int newLength) { // ��������� ������� ������� ������� �������������
	User* _userlisttemp{ new User[newLength] }; // ��������� ������
	if (_length > 0) {
		int elementsToCopy{ (newLength > _length) ? _length : newLength };
		std::copy_n(_userlist, elementsToCopy, _userlisttemp); // ����������� ���������
		delete[] _userlist; // �������� ������� �������
		_userlist = _userlisttemp; // ����� ������ ������ �������(��� ������� ��������� �� �����)
		_length = newLength;
	}
}
void UserList::showUsers() { // ����� ������ �������������
	for (int i = 0; i < _length; i++) {
		_userlist[i].getUser();
	}
}
int UserList::getLength() { // ������� ���������� ������������� (����� ������� �������)
	return _length;
}
/* C�������� */
void UserList::saveMsg(int _i, int _ir, std::string _m) { // ���������� ���������
	if (_ir < 0) {
		resizeMsgList(_count + 1); // ��������� ���������
		_msglist[_count - 1] = Msg(_userlist[_i].getLogin(), std::string("all"), _m);
	}
	else {
		resizeMsgList(_count + 1); // �����
		_msglist[_count - 1] = Msg(_userlist[_i].getLogin(), _userlist[_ir].getLogin(), _m);
	}
}
void UserList::getMsgs(int _i, int _ir) { // ����� ������� ���������
	if (_ir < 0) {
		for (int i = 0; i < _count; i++) { // ��������� ���������
			_msglist[i].getGroup();
		}
	}
	else {
		for (int i = 0; i < _count; i++) { // �����
			_msglist[i].getPrivate(_userlist[_i].getLogin(), _userlist[_ir].getLogin());
		}
	}
}
void UserList::resizeMsgList(int newCount) { // ��������� ������� ������� ������� ���������
	Msg* _msglisttemp{ new Msg[newCount] }; // ������� ��������� ������
	if (_count > 0) {
		int elementsToCopy{ (newCount > _count) ? _count : newCount };
		std::copy_n(_msglist, elementsToCopy, _msglisttemp); // �������� ��
		delete[] _msglist; // ������� ������ ������
		_msglist = _msglisttemp; // ���������� ����� ������ ������ �������; ��� ������� ��������� �� �����
		_count = newCount;
	}
}