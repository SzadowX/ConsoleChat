#pragma once
#include <iostream>
#include <string>
//#include "User.h"

// класс сообщений

class Msg{
private:
	std::string _msg;
	std::string _login;
public:
	Msg(){};
	Msg(std::string msg) : _msg(msg){};
//	Msg(std::string login, std::string msg) : User(login), _msg(msg){};
	Msg(std::string login, std::string msg) : _login(login), _msg(msg){};
	
	void showMsg(); // вывод логина и пароля и статуса
};

//class MsgList : public User{
//private:
//	int _msgcount{};
//	Msg *_msglist{};
//public:
//	MsgList(int msgcount) : _msgcount(msgcount){
//		_msglist = new Msg[_msgcount]{};
//		_msglist[0] = Msg(std::string("Hello"));
//	}
//	
//	~MsgList(){
//		delete[] _msglist;
//	}
//
//	void showMsgs(){ // вывод истории сообщений
//		for(int i = 0; i < _msgcount; i++){
//			_msglist[i].getMsg();
//		}
//	}
//	void addMsg(std::string u, std::string m){
//		_msglist[_msgcount - 1] = Msg(u, m);
//		
//	}
//};
