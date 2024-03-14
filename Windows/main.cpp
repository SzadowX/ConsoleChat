#include <iostream>
#include <string>
#include "Userlist.h"

void userHelp(){
	std::cout << "r\tдля регистрации нового пользователя\nl\tдля входа в аккаунт\nc\tдля вывода списка пользователей\n[h]elp\tдля вывода списка команд\n[q]uit\tдля выхода из программы" << std::endl;
}

int main(){

	setlocale(LC_ALL, "RU");

	UserList userList(1, 1); // создание объекта массива пользователей
	
	std::cout << "---------- Добро пожаловать в чат ----------" << std::endl;
	std::cout << "Для работы с программой используйте:\n";
	userHelp();

	bool running = true;
	while(running){
		std::cout << "Главное меню: ";
		char choice;
		std::cin >> choice;
		
		switch(choice){
			case 'r':
				userList.setUser();
				break;
			case 'l':
				userList.logIn();
				break;
			case 'c':
				std::cout << "\nСписок пользователей:\n----------" << std::endl;
				userList.showUsers();
				std::cout << "----------\n\n";
				break;
			case 'q':
				running = false;
				break;
			default:
				std::cout << "Неверное значение!" << std::endl;
				break;
		}
	}

	return 0;
}
