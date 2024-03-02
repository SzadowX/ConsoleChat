#include <iostream>
//#include "Autorization.h"
using namespace std;

//#include <iostream>
#include <fstream> // ввод-вывод в  файлы
#include <string>
#include <cctype>

//using namespace std;

static bool Logged = false;//Глобальная переменная для проверки зарегистрировался пользователь или нет
void Register()
{
    string username, password;
    cout << "Введите имя для регистрации:" << "-->" << endl;
    cin >> username;
    cout << "Введите пароль для регистрации:" << "-->" << endl;
    cin >> password;
    ofstream file;
    file.open("c:\\" + username + ".txt");
    file << username << endl << password;
    cout << "Регистрация прошла успешно\n" << endl;

}

void Login()
{
    string username, password, un, pw;
    if (Logged ) {
        cout << "Вы уже авторизовались!" << endl;
    }
    else
    {
        cout << "Введите имя для входа:" << "-->" << endl;
        cin >> username;
        cout << "Введите пароль для входа:" << "-->" << endl;
        cin >> password;

        ifstream read("c:\\" + username + ".txt");
        getline(read, un);
        getline(read, pw);

        if (un == username && pw == password)
        {
            cout << "Вы успешно вошли в систему." << endl;
            Logged = true;
        }
        else
        {
            cout << "Введён Неправильный логин или пароль!" << endl;
        }
    }

}

void Exit()
{
    if (Logged)
    {
        cout << "Вы вышли из системы! " << endl;
        Logged = false;
    }
    else
    {
        cout << "Вы не авторизованы!:" << endl;
    }
}



//static bool Logged = false;//Глобальная переменная для проверки 
//авторизован пользователь или нет

int main()
{

    setlocale(LC_ALL, "rus");
    char choice = '0';
    cout << "Для Регистрации в чате введите: 1" << endl << "для Входа:  2" << endl << "для Выхода: 3 " << endl <<"-->";
    while (cin >> choice) 
    {
  
        switch (choice)
        {
        case '1':
            Register();
            break;
        case '2':
            void Login();
            break;
        case '3':
            void Exit();
            break;
        default:
            cout << "Ошибка ввода. Попробуйте снова\n" << "-->" << endl;
        }

    }

    return 0;
}

