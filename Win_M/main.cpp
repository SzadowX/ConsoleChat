#include <Windows.h>
#include <iostream>
#include <string>
#include "Userlist.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
		UserList userList(1, 1); // создание объекта массива пользователей
	cout << "---------- Добро пожаловать в чат ----------" << endl;
	bool running = true;
	while (running) {
		cout << "Для работы с программой используйте:\n";
		cout << "[r]egistration\tдля регистрации нового пользователя\n[l]og in\tдля входа в аккаунт\n[c]atalog\tдля вывода списка пользователей\n[q]uit\tдля выхода из программы\n" << endl;
		cout << "Главное меню: ";
		char choice;
		cin >> choice; // выбор действий пользователя
		cin.ignore(256, '\n'); // игнорирование ввода символов после первого
		switch (choice) {
		case 'r':
			userList.setUser();
			break;
		case 'l':
			userList.logIn();
			break;
		case 'c':
			system("cls");//очищаем экран
			cout << "Список пользователей:\n----------\nлогин\tимя\tстатус\n";
			userList.showUsers();
			cout << "----------\n\n";
			break;
		case 'q':
			running = false;
			break;
		default:
			system("cls");//очищаем экран
			cout << "Неверное значение!\n";
			cout << "Попробуйте снова.\n";
			break;
		}
	}
	return 0;
}