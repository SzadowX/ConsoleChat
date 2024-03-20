
#include "Autorization.h"

//����� �� ������� ��������� �������
void Talk <string>::show(Talk<string>& a, int size)
{
    cout << endl << "�� ������ ������ � ���� ������������ ��������� ������������:" << endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << a[i] << " : ";
    }
    return;
}
void Talk <string>::show1(Talk<string>& a, int size)
{
    cout << "�� ������ ������ � ����� ��� ��������� ���������  ��������� �������������-->" << endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << "#" << i + 1 << " - ��  " << a[i * 2] << "  :'" << a[i * 2 + 1] << "'" << endl;
    }

    cout << endl;
    return;
}
void Talk <string>::show2(Talk<string>& a, int i3, string un)
{
    int ls = 0;
    system("cls");//������� �����
    cout << "������ ��� ������������ '" << un << "' �������� ��������� ���������-->" << endl;
    for (int i = 0; i < i3; ++i)
    {
        if (a[i * 3 + 1] == un)
        {
            ++ls;
            std::cout << "��#" << ls << " - �������� ��:  " << a[i * 3] << "   :'" << a[i * 3 + 2] << "',";
            std::cout << endl;
        }
        if (a[i * 3] == un)
        {
            ++ls;
            std::cout << "��#" << ls << " - ��������� ���: / " << a[i * 3 + 1] << " / :'" << a[i * 3 + 2] << "',";
            std::cout << endl;
        }
    }
    if (ls == 0) { system("cls"); cout << "������ ��� ������������ '" << un << "' �� �������� �� ������ ���������!!" << endl; }
    cout << endl;
    return;
}
void Talk <string>::RegisterM(Talk<string>& a, Talk<string>& a1, Talk<string>& a2, int i)
{
    string username, u_l, P_w;
    std::cout << "������� ��� ��� ����������� " << i + 1 << "-�� ��������� ����  : " << endl;
    std::cin >> username;
    a[i] = username;
    std::cout << "������� (��� ��������) login ��� ����������� " << i + 1 << "-�� ��������� ����  : " << endl;
    std::cin >> u_l;
    a1[i] = u_l;
    cout << "������� (��� ��������) ������ ��� ����������� " << i + 1 << "-�� ��������� ����  : " << endl;
    cin >> P_w;//;
    a2[i] = P_w;
    system("cls");//������� �����
    cout << "����������� ������ �������\n" << endl;
    // show(a, i + 1);
    return;
}

string Talk <string>::Vhod_v_Chat(Talk<string>& a1, Talk<string>& a2, Talk<string>& a3, int n)
{
    string un, P_w, u_log;
    cout << "���� � ���." << endl << "*������� ���� login ��� �����������: ";
    cin >> u_log;
    cout << "*����������� ���� login �������: ";
    cin >> P_w;
    system("cls");//������� �����
    un = " 0";
    for (int i = 0; i < n; i++)  // ���� ������������ � �������� ��� � �������
    {
        if ((a2[i] == u_log) && (a3[i] == P_w))
        {
            un = a1[i];//���������� ��� ��������� ����
            cout << " - ������������, " << a1[i] << " !" << endl << "* ������ ������������� ������* ����������� ����� � ��� ������������." << endl;
        }
    }
    return un;
}
void Talk <string>::Soobschenia(Talk<string>& a, int i2, string mas, string un)
{//  User_Names.Soobschenia( Individual_messages, i2, mas, un);
    a[i2 * 2 + 1] = mas; a[i2 * 2] = un;
    cout << "������������ '" << un << "' �������� ��������� � ����� ���:" << a[i2 * 2 + 1] << " - " << endl;
    cout << "����� ��������� �� ���� �������������:" << endl;
    show1(a, i2 + 1);

    return;//
}

void Talk <string>::Soobschenia_Ind(Talk<string>& a, Talk<string>& a1, int n, int i3, int  num_Polzovat, string mas, string na, string un)
{
    show(a, num_Polzovat);// ������ �������������, �������������� � ���� �� ������ ������ 
    cout << endl << " -  ������� ��� �������� ��� ������� ���������: ";
    cin >> na;
    bool b = true;
    for (int i = 0; i < n; i++)  // ���� ������������ � ������� ��� 
    {
        if (a[i] == na)
        {
            a1[i3 * 3] = un;//��� ����������� ���������
            a1[i3 * 3 + 1] = na;//��� ��������
            a1[i3 * 3 + 2] = mas;//����� ���������
            b = false;
            cout << " -  ���������� ������ ��������� ��� : " << na << endl;
            show2(a1, i3 + 1, un);
        }
    }
    if (b) {
        cout << "������������ � ������ /" << na << "/ �� ��������������� � �������!- ������ ��������� �� ����������!" << endl;
    }
    return;
}
string Talk <string>::Login()
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
void Talk <string>::Exit()
{
    if (Logged = false)
    {
        cout << "�� ����� �� �������! " << endl;
        Logged = true;
    }
    else
    {
        cout << "�� �� �������������� � ����� �� �������!" << endl;
    }
}

void Talk <string>::Test_Names(Talk<string>& a)//
{
    a[0] = "�������"; a[1] = "������"; a[2] = "����";
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
    a[0] = "�������";//�����������
    a[1] = "������";//���������
    a[2] = "������"; a[3] = "������������!"; a[4] = "����"; a[5] = "��� ����?";
    return;
}
void Talk <string>::Test_Ind_messages(Talk<string>& a)
{
    a[0] = "�������";//�����������
    a[1] = "����";//������� ������� ���������
    a[2] = "���� �������?";//���������
    a[3] = "����";//�����������
    a[4] = "�������";//������� ������� ���������
    a[5] = "Hello, ���������-��� �����!";//���������
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
