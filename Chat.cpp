#include <iostream>
#include "Chat.h"
using namespace std;

Users::Users(string name, string login, string password) : _login(login), _password(password), _name(name) {}

void Chat::SignIn() 
{
    string lg, pas, nm;
    cout << "Ââåäèòå ëîãèí: " << endl;
    cin >> lg;
    cout << "Ââåäèòå ïàðîëü: " << endl;
    cin >> pas;
    cout << "Ïðèäóìàéòå èìÿ: " << endl;
    cin >> nm;
    cout << "Âû óñïåøíî çàðåãèñòðèðîâàëèñü" << endl;
}

void Chat::LogIn()
{
    string lg, pas;
    if (isLogin == false)
    {
        cout << "Ââåäèòå ëîãèí: " << endl;
        cin >> lg;
        cout << "Ââåäèòå ïàðîëü: " << endl;
        cin >> pas;
    }
    else
    {
        cout << "Âû óæå àâòîðèçèðîâàíû" << endl;
    }

}

void Chat::LogOut()
{
    if (isLogin == true)
    {
        isLogin = false;
        cout << "Âû âûøëè èç ñèñòåìû" << endl;
    }
    else
    {
        cout << "Âû åù¸ íå àâòîðèçîâàëèñü" << endl;
    }
}
