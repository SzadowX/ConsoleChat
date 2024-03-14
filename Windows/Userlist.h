#pragma once
#include <iostream>
#include <string>
#include <algorithm> // для std::copy_n
#include "User.h"
#include "Msg.h"

// класс списка пользователей

class UserList{
private:
	int _length{};
	int _count{};
	User *_userlist{};
	Msg *_msglist{};
public:
	// конструктор объекта динамического массива списка пользователей
	UserList(int length, int count) : _length(length), _count(count){
		_userlist = new User[_length]{};
		_userlist[0] = User(std::string("admin"),std::string("admin"), false); // создание одного пользователя (админа)
		_msglist = new Msg[_count]{};
		_msglist[0] = Msg(std::string("Default"), std::string("Welcome!"));
	}
	
	~UserList(){
		delete[] _userlist;
	}
	
	// методы класса списка прользователей
	
	bool authCheck(std::string l, std::string p);
	void resize(int newLength); // изменение размера объекта массива пользователей
	void showUsers(); // вывод списка пользователей
	int getLength(); // возврат количества пользователей (равно размеру массива)
	void GetChosenUser(int x); // вызов метода класс пользователя
	void setUser(); // создание нового пользователя
	void logIn(); // вход пользователя в систему
	void logOut(int n); // выход пользователя из чата

	void getMsgs();
	void addMsg(std::string l, std::string m);
	void resizeMsgList(int newCount); // изменение размера объекта массива пользователей
};
