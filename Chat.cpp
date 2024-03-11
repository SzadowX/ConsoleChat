// TALK.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <Windows.h>
#include <iostream>
#include "Autorization.h"
using namespace std;
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <string>

int  main()
{
    setlocale(LC_ALL, "");
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    string username, P_w, un, na, u_log, pw, mas;
    // setlocale(0, "");
    char choice = '0'; char choice1 = '0'; char choice2 = '0'; char choice3; char choice4 = '0'; char choice5 = '0';
    Logged = false;
    int num_Polzovat = 0;//счётчик пользователей
    int n = 20;//число ячеек в одномерном массиве
    int i1 = 0;//переменная для найденного элемента массива
    int i2 = 3;//счётчик общих сообщений
    int i3 = 2;//счётчик личных сообщений
    Talk<string> User_Names(n);
    Talk<string> User_Logins(n);
    Talk<string> Pass_words(n);
    Talk<string>Common_messages(n);
    Talk<string>Individual_messages(n);
    for (int j = 0; j < n; j++)
    {  //----присваиваем элементам массивов имён пользователей и их паролей значения "0"
        User_Names[j] = "0";
        Pass_words[j] = "0";
        User_Logins[j] = "0";
        Common_messages[j] = "0";
        Individual_messages[j] = "0";
    }  //----заполняем   массивы-окончание  
   //Тестирование (задаются условия): на начальный момент в чате уже зарегистрировано 3 пользователя, были посланы сообщения в общий и личные чаты 
    User_Names.Test_Names(User_Names);
    User_Logins.Test_log_ins(User_Logins);
    Pass_words.Test_PWs(Pass_words);
    Individual_messages.Test_Ind_messages(Individual_messages);
    Common_messages.Test_Com_messages(Common_messages);

    cout << "Предлагается консольный чат-мессенджер со следующим  функционалом:" << endl << "регистрация пользователей - логин, пароль, имя"
        << endl << "вход в чат по логину/паролю" << endl << "отправка сообщений конкретному пользователю"
        << endl << "обмен сообщениями между всеми пользователями чата одновременно" << endl
        << "Примечание:  ввод информации разными пользователями осуществляется с одной клавиатуры" << endl;
    // Common_messages.Test_C_messages(Common_messages);
    // Common_messages.show(Common_messages, 5);

    while (choice1 == '0')
    {

        cout << endl << "Клавиатура освободилась: Доступны опции: " << endl << "-----Регистрация в чате - введите: 1" << endl << "----->  Вход в чат:  2"
            << endl << "<-----Выход из чата: 3 " << endl
            << " -----При вводе /4/-на консоль вывводятся сообщения общего чата. " << endl
            << " -----При вводе /5/-на консоль вывводятся сообщения личного чата " << endl << "Ваш выбор -->";

        cin >> choice;
        system("cls");//очищаем экран
        switch (choice)
        {
        case '1':
            //----Регистрация пользователя в системе-задаются массивы, содержащие  имя и пароль пользователей
            User_Names.Register(User_Names, num_Polzovat, 'n');
            User_Logins.Register(User_Logins, num_Polzovat, 'l');
            Pass_words.Register(Pass_words, num_Polzovat, 'p');

            num_Polzovat = num_Polzovat + 1;//добавлен новый пользователь
            cout << P_w << "на данный момент в чате зарегистрированы следующие пользователи:" << endl;
            User_Names.show(User_Names, num_Polzovat);

            break;
        case '2'://----Вход в чат
            //User_Names.Login();

            cout << "Вход в чат. Введите свой login для авторизации: ";
            cin >> u_log;
            cout << "Подтвердите свой login паролем: ";
            cin >> P_w;
            for (int i = 0; i < n; i++)  // ищем соответствие в массивах имён и паролей
            {
                if ((User_Logins[i] == u_log) && (Pass_words[i] == P_w))
                {
                    un = User_Names[i];//определяем имя участника чата
                    cout << " - Здравствуйте, " << User_Names[i] << ".* пароль соответствует логину* Авторизация входа в чат подтверждена." << endl;
                    i1 = i;
                    choice2 = '1';
                }
            }
            choice2 = '1';//**Test1
            if (choice2 == '1')
            {
                choice4 = '1';
                // std::cin.sync();//clear buffer
                std::cin.ignore();
                while (choice4 == '1')
                {
                    Common_messages.show1(Common_messages, i2);
                    cout << " -  Введите текст нового сообщения: " << endl;
                    std::cin.clear();
                    getline(std::cin, mas);
                    system("cls");//очищаем экран
                    cout << " -  Если сообщение предназначено для всех пользователей-введите /1/.При вводе /2/-это сообщение сможет прочитать только один адресат: " << endl;

                    cin >> choice3;

                    // un = "User_Name";
                    switch (choice3)
                    {
                    case '1':
                        Common_messages[i2 * 2] = un;//имя отправителя сообщения
                        Common_messages[i2 * 2 + 1] = mas;//текст сообщения
                        i2 = i2 + 1;
                        choice5 = '1';
                        i1 = i1 + 1;
                        break;
                    case '2':
                        cout << " -  введите имя адресата для личного сообщения: " << endl;
                        cin >> na;
                        Individual_messages[i3 * 3] = un;//имя отправителя сообщения
                        Individual_messages[i3 * 3 + 1] = na;//имя адресата
                        Individual_messages[i3 * 3 + 2] = mas;//текст сообщения
                        i3 = i3 + 1;
                        break;

                    default:  //----обработка неправильного ввода при выборе опции при посылке сообщения
                        cout << "!!Выбор не определён. Попробуйте снова: 1 - общее сообщение в чат; 2 - личное сообщение" << "-->" << endl;
                        choice4 = '1';
                        break;
                    }
                    Common_messages.show1(Common_messages, i2);
                    cout << " -  Написать ещё одно сообщение? введите /1/" << endl << " - Чтобы освободить клавиатуру для другого пользователя-любой другой символ. " << endl;
                    cin >> choice4;

                    //Common_messages.show1(Common_messages,i2);
                    if (choice4 == '1')
                    {
                        // Common_messages.show1(Common_messages, i2);
                        choice5 = '0';
                        cout << " -  Отобразить для /" << un << "/ содержание личного чата - введите /1/" << endl << " -  Продолжить без просмотра личного чата-любой другой символ. " << endl;
                        cin >> choice5;
                        if (choice5 == '1')
                        {
                            Individual_messages.show2(Individual_messages, i3);
                        }

                    }
                    else
                    {
                        system("cls");//очищаем экран
                        cout << un << "  освободил  клавиатуру для ввода. :  -->" << endl;
                        choice4 = '0';
                    }
                    std::cin.ignore();
                }


                choice2 = '0';



            }
            else
            {
                cout << "Неверный пароль или пользовательское имя! Выбор не определён. Возврат в исходное меню -->" << endl;
            }

            break;
        case '3'://----Выход из  чата
            User_Names.Exit();
            choice1 = '1';
            break;


        case '4'://----Вывод на консоль вывводятся сообщения общего чата. 
            cout << " -  При вводе /4/-на консоль вывводятся сообщения общего чата. " << endl;
            choice1 = '1';
            break;
        case '5'://----Вывод на консоль вывводятся сообщения личного чата пользователя авторизированного в данный момент. 
            cout << " -  При вводе /4/-на консоль вывводятся сообщения общего чата. " << endl;
            choice1 = '1';
            break;
        default://----обработка неправильного ввода при выборе опции
            cout << "Ошибка ввода. Попробуйте снова" << "-->" << endl;
            break;
        }

    }
    
    return 0;
}
