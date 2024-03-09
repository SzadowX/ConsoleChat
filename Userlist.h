#include <iostream>
#include <string>
#include <algorithm> // для std::copy_n
#include "User.h"

// класс списка пользователей

class UserList{
private:
	int _length{};
	User *_userlist{};
public:
	// конструктор объекта динамического массива списка пользователей
	UserList(int length) : _length(length){
		_userlist = new User[_length]{};
		_userlist[0] = User(std::string("admin"),std::string("admin"), false); // создание одного пользователя (админа)
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
};
