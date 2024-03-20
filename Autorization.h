#pragma once
#include <iostream>
using namespace std;

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
    int n, m, pr1, i1;
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

    //   �������   ��� �������� ����� �������.
    int getLength() const { return m_length; }
    //    ��������  ������ � ��������� �������.  
    T& operator[](int index)
    {
        // ��������,��� �������� index ����� ���������� ��������
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
    //����� �� ������� ��������� �������
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



