#include <iostream>
#include <string>
#include "user.h"

int main(){
	iUser* userList[1];	// массив объектов пользователей
	userList[0] = new User(std::string("jane"), 1234);

	Msg* msgHistory[10]; // массив сообщений
	int msgCount = 0;

	while(true){
		std::cout << userList[0]->userName() << ": ";
		std::string msg_body;
		std::getline(std::cin, msg_body);
			
		if(msg_body == "quit"){
			break;
		}
		else{
			msgCount += 1;
			msgHistory[msgCount - 1] = new Msg(userList[0]->userName(), msg_body);
		}
	}
	
	for(int i = 0; i < msgCount; i++){
		msgHistory[i]->Show();	
	}

	return 0;
}
