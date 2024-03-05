#include <iostream>
#include "Users.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    
    IUser* users[3];

    users[0] = new User("Joe", "joe", "123");
    users[1] = new User("Max", "max", "qwerty");
    
    string lg, nm, pas;
    char val;
    cin >> val;

    switch (val)
    {
    case 'r':
        cout << "Введите логин: " << endl;
        cin >> lg;
        cout << "Введите пароль: " << endl;
        cin >> pas;
        cout << "Придумайте имя: " << endl;
        cin >> nm;
        users[2] = new User(lg, pas, nm);
        cout << endl;
    default:
        break;
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