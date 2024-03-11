#pragma once
//#ifndef INTARRAY_H
//#define INTARRAY_H
#include <iostream>
using namespace std;
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <string>


static bool Logged = false;//Глобальная переменная для проверки зарегистрировался пользователь или нет
template <typename T>
class Talk
{
private:
    int m_length{};//- размер массива (количество элементов в массиве, доступных пользователю)
    //T* m_data{};//- указатель на область памяти, где хранятся сами элементы массива.
    T* m_data;

public:
    const char* bad_length = "нельзя провести такую операцию-bad_length - новый размер(container)равен 0 или меньше";
    const char* bad_range = "нельзя провести такую операцию-bad_range – выход за пределы допустимого диапазона ";
    int n, m, pr1;

    /*  конструкторы, для 1)создания пустой массива 2) создания массив заранее определенного размера.*/
    Talk() = default;
    Talk(int length) ://

        m_length{ length }
    {
        if ((length == 0) || (length < 0))
        {
            throw bad_length;
        }
        m_data = new T[length]{};
    }
    //деструктор, который освобождает  динамически распределяемые данные.
    ~Talk()
    {
        delete[] m_data;
    }

    

    //функция erase(),   сотрет массив и установит длину равной 0
    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }
    //конструктор копирования массива.
    Talk(const Talk& a)
   
    {
        // устанавливаем размер нового массива
        reallocate(a.getLength());
        std::copy_n(a.m_data, m_length, m_data); // копирование элементов массива
    }
    // оператор присваивания, чтобы мы могли скопировать массив.
    Talk& operator=(const Talk& a)
    {
        if (&a == this)
            return *this;
        // устанавливаем размер нового массива
        reallocate(a.getLength());
        std::copy_n(a.m_data, m_length, m_data); //копируем элементы массива
        return *this;
    }
    //   функция   для возврата длины массива.
    int getLength() const { return m_length; }
    //    оператор  доступ к элементам массива.  
    T& operator[](int index)
    {
        // Проверка,что параметр index имеет допустимое значение
        if (m_length <= index || index < 0)
        {
            throw bad_range;
        }
        return m_data[index];

    }
   
    //вывод на консоль элементов массива
    void show(Talk<T>& a, int size)
    {
        for (int i = 0; i < size; ++i)
        {
            std::cout << a[i] << " ";
        }
        return;
    }

    void show1(Talk<T>& a, int size)
    {
       
        cout << "На данный момент в общий чат поступили сообщения  следующих пользователей-->" << endl;
        for (int i = 0; i < size; ++i)
        {
            std::cout << "#" << i+1 << " - от / " << a[i * 2] << "/ :'" << a[i * 2 + 1] << "',";
            std::cout << endl;
        }
                     
        cout << endl;
        return;
    }
    void show2(Talk<T>& a,  int size)
    {

        cout << "На данный момент вам  поступили личные сообщения от следующих пользователей-->" << endl;
        for (int i = 0; i < size; ++i)
        {
            std::cout << "#" << i+1<<" - от / " << a[i * 3] << " / для / " << a[i * 3 + 1] << "/ :'" << a[i * 3 + 2] << "',";
            std::cout << endl;
        }

        cout << endl;
        return;
    }

    //авто заполнение элементов массива для Теста 1  getline(std::cin, pr2);
    void  Setarr1(Talk<T>& a, int size)
    {
        for (int i = 0; i < size; i++) {
            a[i] = i + 1;
        }
        return;
    }

    void Test_Names(Talk<T>& a)//(Talk<T>& a, char n1)
        // Talk User_Names ("Din", "Max", "Gil", "tm2", "www");
    {
        a[0] = "Валерий";
        a[1] = "Максим";
        a[2] = "Лена";
        return;
    }
    void Test_PWs(Talk<T>& a)//(Talk<T>& a, char n1)
        // Talk User_Names ("Din", "Max", "Gil", "tm2", "www");
    {
        a[0] = "v";
        a[1] = "m";
        a[2] = "l";
        return;
    }
    void Test_log_ins(Talk<T>& a)
    {
        a[0] = "Din";
        a[1] = "Max";
        a[2] = "Dot";
        return;
    }
    void Test_Com_messages(Talk<T>& a)
    {
        a[0] = "Валерий";//отправитель
        a[1] = "Привет";//сообщение
        a[2] = "Максим";
        a[3] = "Здравствуйте!";
        a[4] = "Лена";
        a[5] = "Как дела?";
       // a[3] = "Добрый день!";
        //a[4] = "Хорошего вечера!";
        return;
    }
    void Test_Ind_messages(Talk<T>& a)
    {
        a[0] = "Валерий";//адресат личного сообщения
        a[1] = "Лена";//отправитель
        a[2] = "Куда пропал?";//сообщение
        a[3] = "Лена";//адресат личного сообщения
        a[4] = "Валерий";//отправитель
        a[5] = "Hello, зашиваюсь-дел полно!";//сообщение
        return;
    }


    //поэлементный ввод  данных в массив c клавиатуры
    void Setarr(Talk<T>& a, int size)
    {
        std::cout << "Введите " << size << " элементов(a)  : ";
        for (int i = 0; i < size; i++) {
            std::cin >> a[i];
        }
        return;
    }
    void Poisk(Talk<T>& a, int size, T value1)
    {
        int choice = 2;
        for (int i{ 0 }; i < size; ++i)
        {
            if (a[i] == value1)
            {
                cout << "------> Найден  элемент с индексом :" << i << ' ' << endl;
                choice = 1;
            }
            else
            {

            }
        }
        if (choice == 2)
        {
            cout << "!!!!!!!!  Элементов с таким значением в контейнере НЕТ " << endl;
        }
        return;
    }
    //-----------------------------------------------
    void Register(Talk<T>& a, int i, char v)
    {
        string username,u_l, P_w;
        if (v == 'n')
        {
            std::cout << "Введите имя для регистрации " << i+1 << "-го участника чата  : " << endl;
            std::cin >> username;
            a[i] = username;
        }
        if (v == 'l')
        {
            std::cout << "Введите  login для регистрации " << i + 1 << "-го участника чата  : " << endl;
            std::cin >> u_l;
            a[i] = u_l;
        }
        if (v == 'p')
        {
            cout << "Введите пароль для регистрации " << i+1 << "-го участника чата  : " << endl;
            cin >> P_w;//;
            a[i] = P_w;
            cout << "Регистрация прошла успешно\n" << endl;
        }
 
        return;
    }

    void Soobschenia(Talk<T>& a, int i, string mas, string un)
    {
     
            a[i] = mas;

            cout << "Пользователь '"<< un << "' отправил сообщение в общий чат:" <<  a[i] << " - " << endl;
            cout << "Общие сообщения от всех пользователей:" << endl;
         return;//
     }

    string Login()
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
            un = 'qw';
            pw = '33';
            /* ifstream read("c:\\" + username + ".txt");
            getline(read, un);
        file << username << endl << P_w;
            getline(read, pw);*/

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

    void Exit()
    {
        if (Logged=false)
        {
            cout << "Вы вышли из системы! " << endl;
            Logged = true;
        }
        else
        {
            cout << "Вы не авторизовались и вышли из системы!" << endl;
        }
    }
  






};



