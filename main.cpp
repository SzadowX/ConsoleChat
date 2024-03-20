#include <Windows.h>
#include <iostream>
#include "Autorization.h"
#include "Service.h"
#include <string>
using namespace std;

int  main()
{
  //  setlocale(LC_ALL, "");
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    string username, P_w, un, na, u_log, pw, mas;
    char choice = '0'; char choice1 = '0'; char choice2 = '0'; char choice3; char choice4 = '0'; char choice5 = '0';
    int num_Polzovat = 3;//счётчик зарегистрированных пользователей(в тестовом режиме-уже есть зарегистрированные)
    int n = 20;//задаётся максимальное количество зарегистрированных участников чата
    int i2 = 3;//счётчик общих сообщений (в тестовом режиме-уже есть несколько сообщений)
    int i3 = 2;//счётчик личных сообщений(в тестовом режиме-уже есть несколько сообщений)
    Talk<string> User_Names(n);
    Talk<string> User_Logins(n);
    Talk<string> Pass_words(n);
    Talk<string>Common_messages(n*2);
    Talk<string>Individual_messages(n*3);
    Info<char>Info; Info._Info_messages();//-вывод общей информации о чате
    //Тестирование (задаются условия): на начальный момент в чате уже зарегистрировано 3 пользователя, были посланы сообщения в общий и личные чаты 
    User_Names.Test_1(User_Names, User_Logins, Pass_words, Individual_messages, Common_messages);
    while (choice1 == '0')//основной цикл:1-регистрация пользователя; 2-вход и работа в чате; 3-выход 
    {
        User_Names.show(User_Names, num_Polzovat);
        cout << endl << endl << "Клавиатура освободилась: Доступны опции: " << endl << "   Регистрация в чате - введите: 1" << endl << "   --->  Вход в чат:  2"
            << endl << "   <-- Выход из чата: 3 " << endl << "Ваш выбор-----> ";
        cin >> choice;
        system("cls");//очищаем экран
        switch (choice)
        {//----Регистрация пользователя в системе:
        case '1'://-заполняются данные массивов, хранящие  имя и пароль пользователей
            User_Names.RegisterM(User_Names, User_Logins, Pass_words, num_Polzovat);
            num_Polzovat = num_Polzovat + 1;//добавлен новый пользователь
            break;
        case '2'://----Вход в чат и работа в нем
            un = User_Names.Vhod_v_Chat(User_Names, User_Logins, Pass_words, n);
            choice2 = '1';
            if (un == " 0") { choice2 = '0'; }
            if (choice2 == '1')
            {
                choice4 = '1';
                std::cin.ignore();
                while (choice4 == '1')//цикл - принимает от пользователя сообщение  и направляет его:
                {//1-  в общий чат ; 2 -  в личный чат; + обработка неопределённого выбора 
                    Common_messages.show1(Common_messages, i2);
                    cout << " -  Введите текст нового сообщения: " << endl;
                    std::cin.clear();
                    getline(std::cin, mas);//-считываем сообщение
                    Info._Info_m_1();//очищаем экран, выбор вида сообщения - для общего или  личного чата.

                    cin >> choice3;
                    system("cls");//очищаем экран
                    switch (choice3)
                    {
                    case '1'://-отправить сообщение в общий чат
                        Common_messages.Soobschenia(Common_messages, i2, mas, un);
                        i2 = i2 + 1;
                        break;
                    case '2'://-отправить сообщение в личный чат
                        Individual_messages.Soobschenia_Ind(User_Names, Individual_messages, n, i3, num_Polzovat, mas, na, un);
                        i3 = i3 + 1;
                        break;
                    default:  //----обработка неправильного ввода при выборе опции при посылке сообщения
                        cout << "!Выбор не определён: СООБЩЕНИЕ НЕ ОТПРАВЛЕНО! Попробуйте снова: " << "-->" << endl;
                        choice4 = '1';
                        break;
                    }
                    Info._Info_m_2(un);//диалоговое сообщение по выбору действия:сообщение,просмотр личного чата,или передача клавиатуры другому пользователю
                    cin >> choice4;
                    if (choice4 == '2')
                    {//Отображение личных сообщений для авторизованного на данный момент пользователя  
                        Individual_messages.show2(Individual_messages, i3, un);
                        choice4 = '1';
                    }
                    else
                    {
                        if (choice4 == '1')
                        {
                            system("cls");//очищаем экран  
                        }
                        else
                        {
                            system("cls");//очищаем экран
                            cout << un << "  освободил  клавиатуру для ввода. :  -->" << endl;
                            choice4 = '0';
                        }
                    }
                    std::cin.ignore();
                }
                choice2 = '0';
            }
            else
            {
                cout << " - Введены  ошибочные пароль или логин! * Авторизация входа в чат НЕ подтверждена*" << endl
                    << "   Возврат в исходное меню -->" << endl;
            }
            break;
        case '3'://----Выход из  чата
            User_Names.Exit();
            choice1 = '1';
            break;

        default://----обработка неправильного ввода при выборе опции
            cout << "Ошибка ввода. Попробуйте снова" << "-->" << endl;
            break;
        }
    }


    return 0;
}

