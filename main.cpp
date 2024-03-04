#include <iostream>
#include "Chat.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    
    IChat* users[3];
    Chat* chat{};

    users[0] = new Users("Joe", "joe", "123");
    users[1] = new Users("Max", "max", "qwerty");
    
    string lg, nm, pas;
    char key;

    cout << "Введите ключ: r - для регистрации, l - для авторизации, q - для выхода из аккаунта" << endl;
    cin >> key;

    switch (key)
    {
    case 'r':
        chat->SignIn();
        users[2] = new Users(lg, pas, nm);
        cout << endl;
    case 'l':
        chat->LogIn();
    case 'q':
        chat->LogOut();
    default:
        cout << "Вы ввели неверный ключ" << endl;
        cin >> key;
    }
    

    cout << "Все пользователи чата: " << endl;
    cout << endl;
    users[0] -> Show();
    cout << endl;
    users[1] -> Show();
    cout << endl;
    users[2] -> Show();

    delete users[0];
    delete users[1];
    delete users[2];

    return 0;
}