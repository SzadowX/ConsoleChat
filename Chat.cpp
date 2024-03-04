#include <iostream>
#include "Chat.h"
using namespace std;

Users::Users(string name, string login, string password) : _login(login), _password(password), _name(name) {}

static bool isLogin = false;

void Users::Show()
{
	cout << "User name: " << _name << endl;
	cout << "User login: " << _login << endl;
	cout << "User password: " << _password << endl;
}

void Chat::SignIn() 
{
    cout << "������� �����: " << endl;
    cin >> this->_login;
    cout << "������� ������: " << endl;
    cin >> this->_password;
    cout << "���������� ���: " << endl;
    cin >> this->_name;
    cout << "�� ������� ������������������" << endl;
}

void Chat::LogIn()
{
    string lg, pas;
    if (isLogin == false)
    {
        cout << "������� �����: " << endl;
        cin >> lg;
        cout << "������� ������: " << endl;
        cin >> pas;
    }
    else
    {
        cout << "�� ��� ��������������" << endl;
    }

    if (lg == this->_login && pas == this->_password)
    {
        cout << "�� ������� ��������������" << endl;
        isLogin = true;
    }
    else
    {
        cout << "�� ����� �������� ����� ��� ������" << endl;
    }
}

void Chat::LogOut()
{
    if (isLogin)
    {
        isLogin = false;
        cout << "�� ����� �� �������" << endl;
    }
    else
    {
        cout << "�� ��� �� ��������������" << endl;
    }
}