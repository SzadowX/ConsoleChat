#include <iostream>
#include "Chat.h"
using namespace std;

Users::Users(string name, string login, string password) : _login(login), _password(password), _name(name) {}

void Chat::SignIn() 
{
    string lg, pas, nm;
    cout << "Введите логин: " << endl;
    cin >> lg;
    cout << "Введите пароль: " << endl;
    cin >> pas;
    cout << "Придумайте имя: " << endl;
    cin >> nm;
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

}

void Chat::LogOut()
{
    if (isLogin == true)
    {
        isLogin = false;
        cout << "Вы вышли из системы" << endl;
    }
    else
    {
        cout << "Вы ещё не авторизовались" << endl;
    }
}
