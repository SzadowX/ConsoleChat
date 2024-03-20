#pragma once
#include <iostream>
using namespace std;

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
    int n, m, pr1, i1;
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

    //   функция   для возврата длины массива.
    int getLength() const { return m_length; }
    //    оператор  доступ к элементам массива.  
    T& operator[](int index)
    {
        // Проверка,что параметр index имеет допустимое значение
        if (m_length <= index || index < 0)
        {
           // throw bad_range;
        }
        return m_data[index];

    }

    void Test_Names(Talk<T>& a);//
    void Test_PWs(Talk<T>& a);//
    void Test_log_ins(Talk<T>& a);
    void Test_Com_messages(Talk<T>& a);
    void Test_Ind_messages(Talk<T>& a);
    void Test_1(Talk<T>& a1, Talk<T>& a2, Talk<T>& a3, Talk<T>& a4, Talk<T>& a5);
    //вывод на консоль элементов массива
    void show(Talk<T>& a, int size);
    void show1(Talk<T>& a, int size);
    void show2(Talk<T>& a, int i3, string un);
    void RegisterM(Talk<T>& a, Talk<T>& a1, Talk<T>& a2, int i);
    string Vhod_v_Chat(Talk<T>& a1, Talk<T>& a2, Talk<T>& a3, int n);
    void Soobschenia(Talk<T>& a, int i2, string mas, string un);
    void Soobschenia_Ind(Talk<T>& a, Talk<T>& a1, int n, int i3, int  num_Polzovat, string mas, string na, string un);
    string Login();
    void Exit();
};



