#include <iostream>
#include <string>
#include "user.h"

int main(){	
	std::cout << "Добро пожаловать в чат" << std::endl;
	
	User* userList[5];	// список пользователей
	int userCount = 2; // счетчик зарегистрированных пользоватлей	

	Msg* msgHistory[10]; // массив сообщений
	int msgCount = 0; // счетчик соотбений в истории

	userList[0] = new User(std::string("jane"),std::string("1234")); // пользователь 1
	userList[1] = new User(std::string("john"), std::string("4321")); // пользователь 2
	
	while(true){
		std::string login; // логин
		std::string pass; // пароль
		std::string name; // имя

		const chat choice;
		std::cout << "Для работы с программой исппользуйте:\n[a]dd для регистрации нового пользователя\nlog[i]n для входа в аккаунт\nlog[o]ut для выхода из аккаунта\n[q]uit для выхода из программы" << std::endl;	
		std::cin >> choice;

		switch(choice){
			case('a'):
				std::cout << "введите логин: ";	
				std::cin >> login; // оставляет после себя символ перенеоса строки
				
				if(login == "quit"){
					break;
				}
				
				std::cout << "введите пароль: ";	
				std::cin >> pass; // оставляет после себя символ перенеоса строки

				std::cin.ignore(); // игнорирование символа после cin, чтобы getline не считывал пустое значение
				
				for(int i = 0; i < userCount; i++){
//					while(login == userList[i]->userName()){
					while(userList[i]->AuthCheck(login, pass)){
						std::string msg_body;
						std::cout << userList[i]->userName() << ": ";
						std::getline(std::cin, msg_body);
					
						if(msg_body == "quit"){
							break;
						}
						else{
							msgCount += 1;
							if(msgCount > 10){
							
							}
							msgHistory[msgCount - 1] = new Msg(userList[i]->userName(), msg_body);
						}
					}
				break;
			case('i'):
				break;
			case('o'):
				break;
			case('q'):
				break;
			default:

		}	
	}

	for(int i = 0; i < msgCount; i++){
		msgHistory[i]->Show();	
	}

	for(int i = 0; i < userCount; i++){ // деструкторы объектов пользователей
		delete userList[i];
	}
	for(int i = 0; i < msgCount; i++){ // деструкторы объектов сообщений
		delete msgHistory[i];
	}

	return 0;
}
