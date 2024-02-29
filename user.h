#pragma once

template<typename T>
class User{
private:
	string _login; // логин
	string _pass; // пароль
	string _name; // имя
	string _usersList; // двумерный массив пользователей ключ:значение
public:
	User(){}
	
	void addUser(string name, char pass){} // добавить п
//	void delUser(string name, char pass){} // удалить п
//	void showUser(string name){} // инфа о пользователе
	string listUsers(){} // список пользователей
};

template<typename T>
class Message{
private:
	string _user; // пользователь
//	string _time; // время отправки
	string _body; // тело сообщения
	string _history; // массив
public:
	void sendMsg(){}
	void showHist(){}

};
