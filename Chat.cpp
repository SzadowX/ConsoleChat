#include <iostream>
#include "Chat.h"
using namespace std;

Users::Users(string name, string login, string password) : _login(login), _password(password), _name(name) {}

void Users::Show()
{
	cout << "User name: " << _name << endl;
	cout << "User login: " << _login << endl;
	cout << "User password: " << _password << endl;
}

void Chat::SignIn() 
{
    string lg, pas, nm;
    cout << "������� �����: " << endl;
    cin >> lg;
    cout << "������� ������: " << endl;
    cin >> pas;
    cout << "���������� ���: " << endl;
    cin >> nm;
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

}

void Chat::LogOut()
{
    if (isLogin == true)
    {
        isLogin = false;
        cout << "�� ����� �� �������" << endl;
    }
    else
    {
        cout << "�� ��� �� ��������������" << endl;
    }
}