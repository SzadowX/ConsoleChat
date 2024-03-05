#include <iostream>
#include "Chat.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    
    Users* users[3];
    Chat* chat{};
    int userCount = 3;

    users[0] = new Users("Joe", "joe", "123");
    users[1] = new Users("Max", "max", "qwerty");
    
    string lg, nm, pas;
    char key;

    while (true)
    {
        cout << "Введите ключ: r - для регистрации, l - для авторизации, q - для выхода из аккаунта, e - для выхода" << endl;
        cin >> key;
        switch (key)
        {
        case 'r':
            //chat->SignIn();
            cin >> lg;
            cin >> pas;
            cin >> nm;
            users[2] = new Users(lg, pas, nm);
            cout << endl;
            break;
        case 'l':
            cin >> lg;
            cin >> pas;
            for (int i = 0; i < userCount; i++)
            {
                if (users[i]->AuthCheck(lg, pas))
                {
                    cout << "Добро пожаловать " << endl;
                    chat->isLogin = true;
                    break;
                }
                else
                {
                    cout << "wrong";
                }
            }
            break;
        case 'q':
            chat->LogOut();
            break;
        case 'e':
            return 0;
        default:
            cout << "Вы ввели неверный ключ" << endl;
            break;
        }
        //system("cls");
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
    delete chat;

    return 0;
}