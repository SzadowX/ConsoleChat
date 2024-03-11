#pragma once
//#ifndef INTARRAY_H
//#define INTARRAY_H
#include <iostream>
using namespace std;
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <string>


static bool Logged = false;//���������� ���������� ��� �������� ����������������� ������������ ��� ���
template <typename T>
class Talk
{
private:
    int m_length{};//- ������ ������� (���������� ��������� � �������, ��������� ������������)
    //T* m_data{};//- ��������� �� ������� ������, ��� �������� ���� �������� �������.
    T* m_data;

public:
    const char* bad_length = "������ �������� ����� ��������-bad_length - ����� ������(container)����� 0 ��� ������";
    const char* bad_range = "������ �������� ����� ��������-bad_range � ����� �� ������� ����������� ��������� ";
    int n, m, pr1;

    /*  ������������, ��� 1)�������� ������ ������� 2) �������� ������ ������� ������������� �������.*/
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
    //����������, ������� �����������  ����������� �������������� ������.
    ~Talk()
    {
        delete[] m_data;
    }

    

    //������� erase(),   ������ ������ � ��������� ����� ������ 0
    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }
    //����������� ����������� �������.
    Talk(const Talk& a)
   
    {
        // ������������� ������ ������ �������
        reallocate(a.getLength());
        std::copy_n(a.m_data, m_length, m_data); // ����������� ��������� �������
    }
    // �������� ������������, ����� �� ����� ����������� ������.
    Talk& operator=(const Talk& a)
    {
        if (&a == this)
            return *this;
        // ������������� ������ ������ �������
        reallocate(a.getLength());
        std::copy_n(a.m_data, m_length, m_data); //�������� �������� �������
        return *this;
    }
    //   �������   ��� �������� ����� �������.
    int getLength() const { return m_length; }
    //    ��������  ������ � ��������� �������.  
    T& operator[](int index)
    {
        // ��������,��� �������� index ����� ���������� ��������
        if (m_length <= index || index < 0)
        {
            throw bad_range;
        }
        return m_data[index];

    }
   
    //����� �� ������� ��������� �������
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
       
        cout << "�� ������ ������ � ����� ��� ��������� ���������  ��������� �������������-->" << endl;
        for (int i = 0; i < size; ++i)
        {
            std::cout << "#" << i+1 << " - �� / " << a[i * 2] << "/ :'" << a[i * 2 + 1] << "',";
            std::cout << endl;
        }
                     
        cout << endl;
        return;
    }
    void show2(Talk<T>& a,  int size)
    {

        cout << "�� ������ ������ ���  ��������� ������ ��������� �� ��������� �������������-->" << endl;
        for (int i = 0; i < size; ++i)
        {
            std::cout << "#" << i+1<<" - �� / " << a[i * 3] << " / ��� / " << a[i * 3 + 1] << "/ :'" << a[i * 3 + 2] << "',";
            std::cout << endl;
        }

        cout << endl;
        return;
    }

    //���� ���������� ��������� ������� ��� ����� 1  getline(std::cin, pr2);
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
        a[0] = "�������";
        a[1] = "������";
        a[2] = "����";
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
        a[0] = "�������";//�����������
        a[1] = "������";//���������
        a[2] = "������";
        a[3] = "������������!";
        a[4] = "����";
        a[5] = "��� ����?";
       // a[3] = "������ ����!";
        //a[4] = "�������� ������!";
        return;
    }
    void Test_Ind_messages(Talk<T>& a)
    {
        a[0] = "�������";//������� ������� ���������
        a[1] = "����";//�����������
        a[2] = "���� ������?";//���������
        a[3] = "����";//������� ������� ���������
        a[4] = "�������";//�����������
        a[5] = "Hello, ���������-��� �����!";//���������
        return;
    }


    //������������ ����  ������ � ������ c ����������
    void Setarr(Talk<T>& a, int size)
    {
        std::cout << "������� " << size << " ���������(a)  : ";
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
                cout << "------> ������  ������� � �������� :" << i << ' ' << endl;
                choice = 1;
            }
            else
            {

            }
        }
        if (choice == 2)
        {
            cout << "!!!!!!!!  ��������� � ����� ��������� � ���������� ��� " << endl;
        }
        return;
    }
    //-----------------------------------------------
    void Register(Talk<T>& a, int i, char v)
    {
        string username,u_l, P_w;
        if (v == 'n')
        {
            std::cout << "������� ��� ��� ����������� " << i+1 << "-�� ��������� ����  : " << endl;
            std::cin >> username;
            a[i] = username;
        }
        if (v == 'l')
        {
            std::cout << "�������  login ��� ����������� " << i + 1 << "-�� ��������� ����  : " << endl;
            std::cin >> u_l;
            a[i] = u_l;
        }
        if (v == 'p')
        {
            cout << "������� ������ ��� ����������� " << i+1 << "-�� ��������� ����  : " << endl;
            cin >> P_w;//;
            a[i] = P_w;
            cout << "����������� ������ �������\n" << endl;
        }
 
        return;
    }

    void Soobschenia(Talk<T>& a, int i, string mas, string un)
    {
     
            a[i] = mas;

            cout << "������������ '"<< un << "' �������� ��������� � ����� ���:" <<  a[i] << " - " << endl;
            cout << "����� ��������� �� ���� �������������:" << endl;
         return;//
     }

    string Login()
    {
        string username, P_w, un, pw;
        if (Logged = true) {
            cout << "�� ��� ��������������!" << endl;
        }
        else
        {
            cout << "������� ��� ��� �����:" << "-->" << endl;
            cin >> username;
            cout << "������� ������ ��� �����:" << "-->" << endl;
            cin >> P_w;
            un = 'qw';
            pw = '33';
            /* ifstream read("c:\\" + username + ".txt");
            getline(read, un);
        file << username << endl << P_w;
            getline(read, pw);*/

            if (un == username && pw == P_w)
            {
                cout << "�� ������� ����� � �������." << endl;
                Logged = true;
            }
            else
            {
                cout << "����� ������������ ����� ��� ������!" << endl;
            }
        }
        return username, P_w, un, pw;
    }

    void Exit()
    {
        if (Logged=false)
        {
            cout << "�� ����� �� �������! " << endl;
            Logged = true;
        }
        else
        {
            cout << "�� �� �������������� � ����� �� �������!" << endl;
        }
    }
  






};



