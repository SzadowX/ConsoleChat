
#include "Autorization.h"

//вывод на консоль элементов массива
void Talk <string>::show(Talk<string>& a, int size)
{
    cout << endl << "на данный момент в чате авторизованы следующие пользователи:" << endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << a[i] << " : ";
    }
    return;
}
void Talk <string>::show1(Talk<string>& a, int size)
{
    cout << "На данный момент в общий чат поступили сообщения  следующих пользователей-->" << endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << "#" << i + 1 << " - от  " << a[i * 2] << "  :'" << a[i * 2 + 1] << "'" << endl;
    }

    cout << endl;
    return;
}
void Talk <string>::show2(Talk<string>& a, int i3, string un)
{
    int ls = 0;
    system("cls");//очищаем экран
    cout << "Личный чат пользователя '" << un << "' содержит следующие сообщения-->" << endl;
    for (int i = 0; i < i3; ++i)
    {
        if (a[i * 3 + 1] == un)
        {
            ++ls;
            std::cout << "лс#" << ls << " - получено от:  " << a[i * 3] << "   :'" << a[i * 3 + 2] << "',";
            std::cout << endl;
        }
        if (a[i * 3] == un)
        {
            ++ls;
            std::cout << "лс#" << ls << " - отпрвлено для: / " << a[i * 3 + 1] << " / :'" << a[i * 3 + 2] << "',";
            std::cout << endl;
        }
    }
    if (ls == 0) { system("cls"); cout << "Личный чат пользователя '" << un << "' НЕ содержит ни одного сообщения!!" << endl; }
    cout << endl;
    return;
}
void Talk <string>::RegisterM(Talk<string>& a, Talk<string>& a1, Talk<string>& a2, int i)
{
    string username, u_l, P_w;
    std::cout << "Введите имя для регистрации " << i + 1 << "-го участника чата  : " << endl;
    std::cin >> username;
    a[i] = username;
    std::cout << "Введите (без пробелов) login для регистрации " << i + 1 << "-го участника чата  : " << endl;
    std::cin >> u_l;
    a1[i] = u_l;
    cout << "Введите (без пробелов) пароль для регистрации " << i + 1 << "-го участника чата  : " << endl;
    cin >> P_w;//;
    a2[i] = P_w;
    system("cls");//очищаем экран
    cout << "Регистрация прошла успешно\n" << endl;
    // show(a, i + 1);
    return;
}

string Talk <string>::Vhod_v_Chat(Talk<string>& a1, Talk<string>& a2, Talk<string>& a3, int n)
{
    string un, P_w, u_log;
    cout << "Вход в чат." << endl << "*Введите свой login для авторизации: ";
    cin >> u_log;
    cout << "*Подтвердите свой login паролем: ";
    cin >> P_w;
    system("cls");//очищаем экран
    un = " 0";
    for (int i = 0; i < n; i++)  // ищем соответствие в массивах имён и паролей
    {
        if ((a2[i] == u_log) && (a3[i] == P_w))
        {
            un = a1[i];//определяем имя участника чата
            cout << " - Здравствуйте, " << a1[i] << " !" << endl << "* пароль соответствует логину* Авторизация входа в чат подтверждена." << endl;
        }
    }
    return un;
}
void Talk <string>::Soobschenia(Talk<string>& a, int i2, string mas, string un)
{//  User_Names.Soobschenia( Individual_messages, i2, mas, un);
    a[i2 * 2 + 1] = mas; a[i2 * 2] = un;
    cout << "Пользователь '" << un << "' отправил сообщение в общий чат:" << a[i2 * 2 + 1] << " - " << endl;
    cout << "Общие сообщения от всех пользователей:" << endl;
    show1(a, i2 + 1);

    return;//
}

void Talk <string>::Soobschenia_Ind(Talk<string>& a, Talk<string>& a1, int n, int i3, int  num_Polzovat, string mas, string na, string un)
{
    show(a, num_Polzovat);// список пользователей, авторизованных в чате на данный момент 
    cout << endl << " -  введите имя адресата для личного сообщения: ";
    cin >> na;
    bool b = true;
    for (int i = 0; i < n; i++)  // ищем соответствие в массиве имён 
    {
        if (a[i] == na)
        {
            a1[i3 * 3] = un;//имя отправителя сообщения
            a1[i3 * 3 + 1] = na;//имя адресата
            a1[i3 * 3 + 2] = mas;//текст сообщения
            b = false;
            cout << " -  отправлено личное сообщение для : " << na << endl;
            show2(a1, i3 + 1, un);
        }
    }
    if (b) {
        cout << "пользователь с именем /" << na << "/ не зарегистрирован в системе!- личное сообщение НЕ отправлено!" << endl;
    }
    return;
}
string Talk <string>::Login()
{
    string username, P_w, un, pw;
    if (Logged = true) {
        cout << "Вы уже авторизовались!" << endl;
    }
    else
    {
        cout << "Введите имя для входа:" << "-->" << endl;
        cin >> username;
        cout << "Введите пароль для входа:" << "-->" << endl;
        cin >> P_w;
        if (un == username && pw == P_w)
        {
            cout << "Вы успешно вошли в систему." << endl;
            Logged = true;
        }
        else
        {
            cout << "Введён Неправильный логин или пароль!" << endl;
        }
    }
    return username, P_w, un, pw;
}
void Talk <string>::Exit()
{
    if (Logged = false)
    {
        cout << "Вы вышли из системы! " << endl;
        Logged = true;
    }
    else
    {
        cout << "Вы не авторизовались и вышли из системы!" << endl;
    }
}

void Talk <string>::Test_Names(Talk<string>& a)//
{
    a[0] = "Валерий"; a[1] = "Максим"; a[2] = "Лена";
    return;
}
void Talk <string>::Test_PWs(Talk<string>& a)//
{
    a[0] = "v"; a[1] = "m"; a[2] = "l";
    return;
}
void Talk <string>::Test_log_ins(Talk<string>& a)
{
    a[0] = "Din"; a[1] = "m"; a[2] = "l";
    return;
}
void Talk <string>::Test_Com_messages(Talk<string>& a)
{
    a[0] = "Валерий";//отправитель
    a[1] = "Привет";//сообщение
    a[2] = "Максим"; a[3] = "Здравствуйте!"; a[4] = "Лена"; a[5] = "Как дела?";
    return;
}
void Talk <string>::Test_Ind_messages(Talk<string>& a)
{
    a[0] = "Валерий";//отправитель
    a[1] = "Лена";//адресат личного сообщения
    a[2] = "Куда пропала?";//сообщение
    a[3] = "Лена";//отправитель
    a[4] = "Валерий";//адресат личного сообщения
    a[5] = "Hello, зашиваюсь-дел полно!";//сообщение
    return;
}
void Talk <string>::Test_1(Talk<string>& a1, Talk<string>& a2, Talk<string>& a3, Talk<string>& a4, Talk<string>& a5)
{
    Test_Names(a1);
    Test_log_ins(a2);
    Test_PWs(a3);
    Test_Ind_messages(a4);
    Test_Com_messages(a5);
    return;
}
