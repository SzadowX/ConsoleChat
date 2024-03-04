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
    cout << "Введите логин: " << endl;
    cin >> this->_login;
    cout << "Введите пароль: " << endl;
    cin >> this->_password;
    cout << "Придумайте имя: " << endl;
    cin >> this->_name;
    cout << "Вы успешно зарегистрировались" << endl;
}

void Chat::LogIn()
{
    string lg, pas;
    if (isLogin == false)
    {
        cout << "Введите логин: " << endl;
        cin >> lg;
        cout << "Введите пароль: " << endl;
        cin >> pas;
    }
    else
    {
        cout << "Вы уже авторизированы" << endl;
    }

    if (lg == this->_login && pas == this->_password)
    {
        cout << "Вы успешно авторизовались" << endl;
        isLogin = true;
    }
    else
    {
        cout << "Вы ввели неверный логин или пароль" << endl;
    }
}

void Chat::LogOut()
{
    if (isLogin)
    {
        isLogin = false;
        cout << "Вы вышли из системы" << endl;
    }
    else
    {
        cout << "Вы ещё не авторизовались" << endl;
    }
}