#include <iostream>
#include <string>
#include "Userlist.h"
using namespace std;

void userHelp(){
	cout << "[r]egistration\tдля регистрации нового пользователя\n[l]og in\tдля входа в аккаунт\n[c]atalog\tдля вывода списка пользователей\n[q]uit\tдля выхода из программы\n" << endl;
}

int main(){
	UserList userList(1, 1); // создание объекта массива пользователей
	
	cout << "---------- Добро пожаловать в чат ----------" << endl;

	bool running = true;
	while(running){
		cout << "Для работы с программой используйте:\n";
		userHelp();

		cout << "Главное меню: ";
		char choice;
		cin >> choice; // выбор действий пользователя
		cin.ignore(256, '\n'); // игнорирование ввода символов после первого
		
		switch(choice){
			case 'r':
				userList.setUser();
				break;
			case 'l':
				userList.logIn();
				break;
			case 'c':
				system("clear");
				cout << "Список пользователей:\n----------\nлогин\tимя\tстатус\n";
				userList.showUsers();
				cout << "----------\n\n";
				break;
			case 'q':
				running = false;
				break;
			default:
				system("clear");
				cout << "Неверное значение!\n";
				break;
		}
	}

	return 0;
}
