#pragma once
#include <iostream>
#include <string>
#include "User.h"

/* класс сообщений */

class Msg : public User{
private:
	std::string _login;
	std::string _recipient;
	std::string _msg;
public:
	Msg(){};
	Msg(std::string login, std::string msg) : _login(login), _msg(msg){};
	Msg(std::string login, std::string recipient, std::string msg) : _login(login), _recipient(recipient), _msg(msg){};

	~Msg(){};
	
	void getPrivate(std::string l, std::string r); // вывод личных сообщений
	void getGroup(); // вывод групповых сообщений
};

/*
class Dialogs{
private:
	int _msgCount{};
	Msg *_msgListp{};
public:
	Dialogs(){};
	Dialogs(int msgCount) : _msgCount(msgCount){
		_msgListp = new Msg[_msgCount]{};
		_msgListp[0] = Msg(std::string("user1"), std::string("Добро пожаловать!"));	
	}
	
	~Dialogs(){
		delete[] _msgListp;
	}

	void ShowM(){
		for(int i = 0; i < _msgCount; i++){
			_msgListp[i].showMsg();
		}
	}
};
*/

//	void showMsgs(){ // вывод истории сообщений
//		for(int i = 0; i < _msgc; i++){
//			_msglist[i].getMsg();
//		}
//	}
//	void addMsg(std::string u, std::string m){
//		_msglist[_msgc - 1] = Msg(u, m);
//		
//	}
//};
