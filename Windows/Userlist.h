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
	User *_userlist{};
	int _count{};
	Msg *_msglist{};
public:
	
	/* конструктор объекта динамического массива списка пользователей */
	
	UserList(int length, int count) : _length(length), _count(count){
		_userlist = new User[_length]{};  // массив пользоваетелей
		_userlist[0] = User(std::string("admin"),std::string("admin")); // создание одного пользователя (админа)
		_msglist = new Msg[_count]{};  // массив сообщений
		_msglist[0] = Msg(_userlist[0].getLogin(), std::string("Welcome!"));  // приветствие от админа
	}
	
	~UserList(){
		delete[] _userlist;
		delete[] _msglist;
	}
	
	/* методы класса списка прользователей */
	/* пользователь */

	bool authCheck(std::string l, std::string p);
	int getIndex(std::string l); // возврат индекса пользователя по логину
	void setUser(); // создание нового пользователя
	void logIn(); // вход пользователя в систему
	void logOut(int n); // выход пользователя из чата
	void userTyping(int i, int j); //  блок ввода сообщения 

	/* массив пользователей */

	void resize(int newLength); // изменение размера объекта массива пользователей
	void showUsers(); // вывод списка пользователей
	int getLength(); // возврат количества пользователей (равно размеру массива)

	/* сообщения */

	void saveMsg(int _i, int _ir, std::string _m);
	void getMsgs(int _i, int _ir);
	void resizeMsgList(int newCount); // изменение размера объекта массива сообщений
};
