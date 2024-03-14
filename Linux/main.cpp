#include <iostream>
#include <string>
#include "Userlist.h"

void userHelp(){
	std::cout << "1\tдля регистрации нового пользователя\n2\tдля входа в аккаунт\n3\tдля вывода списка пользователей\n4\tдля поиска пользователя по логину\n[h]elp\tдля вывода списка команд\n[q]uit\tдля выхода из программы" << std::endl;
}

int main(){
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
			case '1':
				userList.setUser();
				break;
			case '2':
				userList.logIn();
				break;
			case '3':
				std::cout << "\nСписок пользователей:\n----------" << std::endl;
				userList.showUsers();
				std::cout << "----------\n\n";
				break;
			case '4':
				break;
			case 'h':
				userHelp();
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