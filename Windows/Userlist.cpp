#include <iostream>
#include <string>
#include <algorithm> // для std::copy_n
#include "Userlist.h"

/* Пользователь */

bool UserList::authCheck(std::string l, std::string p){ // проверка логина и пароля - авторизация пользователя
	for(int i = 0; i < _length; i++)
		if(l == _userlist[i].getLogin()){
			if(p == _userlist[i].getPass()){
				std::cout << "----- Пользователь " << l << " вошёл в чат!\n" << std::endl;
				_userlist[i].setStatus(true);
				return true;
			}
			std::cout << "----- Неверный логин или пароль!\n" << std::endl;
			return false;
		}
	std::cout << "----- Неверный логин или пароль!\n" << std::endl;
	return false;
}

int UserList::getIndex(std::string l){ // поиск индекса пользователя по имени
	for(int i = 0; i < _length; i++){
		if(l == _userlist[i].getLogin()){
			return i;
		}
	}
	std::cout << "----- Пользователь не найден!\n" << std::endl;
	return -1;
}
		
void UserList::setUser(){ // создание нового пользователя
	system("cls");
	while(true){
		bool available{false}; // доступность логина
		std::string _l{}, _p{}; // переменные для ввода логина и пароля
		std::cout << "---------- Регистрация нового пользователя ----------\nВведите логин (quit для отмены): ";
		std::cin >> _l;
				
		if(_l == "quit"){ // отмена вызова
			std::cout << "----- Отмена!\n" << std::endl;
			break;
		}
		
		/* проверка наличия логина в системе */

		for(int i = 0; i < _length; i++){
			if(_l == _userlist[i].getLogin()){
				std::cout << "----- Логин занят, выберите другой логин!\n" << std::endl;
				available = false;
				break;
			}
			else{
				available = true;
			}
		}
			
		if(available){
			std::cout << "Введите пароль:  ";
			std::cin >> _p;
			resize(_length + 1); // увеличение массива пользователей
			_userlist[_length - 1] = User(_l, _p); // создание нового объекта пользователя 
			std::cout << "----- Пользователь " << _l << " зарегистрирован\n" << std::endl;
			break;
		}
	}
}

void UserList::logIn(){ // вход пользователя в систему
	
	/* вход пользователя */

	system("cls");
	int attempts = 3; // количество потыток входа(в данном случае 3)
	std::string _l{}, _p{};
	int i{};
	std::cout << "---------- Авторизация ----------\n";
	while(attempts > 0){
		std::cout << "Введите логин и пароль (у вас осталось " << attempts << " попытки): ";
		std::cin >> _l >> _p;
			
		if(authCheck(_l, _p)){
			attempts = -1; // выход из цикла при успешной авторизации
			i = getIndex(_l);
		}
		else{
			attempts--; // уменьшение кол-ва попыток при ошибке в логине или пароле
		}
	}
	
	if(attempts == 0){ // ошибка авторизации
		std:: cout << "----- Превышен лимит попыток!\n" << std::endl;
	}
	
	/* переход в нужный диалог */

	while(_userlist[i].getStatus()){
		system("cls");
		std::cout << "Введите имя собеседника:\n----------\nall (общий диалог)\n";
		showUsers(); // список диалогов (пользователей)
		std::cout << "----------\n";
		std::cout << _l << ": "; // имя отправителя
		std::string c;
		std::cin >> c; // имя получателя
		std::cin.ignore(); // игнорирование символа после cin, чтобы getline не считывал пустое значение
		int ir; // индекс получателя
		
		if(c == "quit"){ // выход из цикла (пользователя из системы)
			std::cout << "----- Пользователь вышел из чата!\n" << std::endl;
			logOut(i); // вызов выхода пользователя
			system("clear");
		}
		else if(c == "all"){ // переход в групповой чат
			system("clear");
			ir = -1;
			std::cout << "---------- Общий диалог ----------" << std::endl;
			getMsgs(i, ir);
			userTyping(i, ir);
		}
		else{ // переход в лс
			ir = getIndex(c); // индекс получателя
			if(ir >= 0){
				system("clear");
				std::cout << "---------- Собеседник  " << _userlist[ir].getLogin() << " ----------" << std::endl; 
				getMsgs(i, ir);
				userTyping(i, ir);
			}
		}
	}
}

void UserList::logOut(int n){ // выход пользователя из чата
	_userlist[n].setStatus(false);
}

void UserList::userTyping(int i, int j){ // блок ввода сообщений
	while(_userlist[i].getStatus()){
		std::string msg_body; // тело сообщения
		std::cout << _userlist[i].getLogin() << ": "; // имя отправителя
		std::getline(std::cin, msg_body); // ввод

		if(msg_body == "quit"){ // выход из цикла (диалога)
			std::cout << "----- Пользователь вышел из диалога!\n" << std::endl;
			system("clear");
			break;
		}
		else{
			saveMsg(i, j, msg_body); // сохранение адресанта:адресата:сообщения (личка)
		}
	}
}

/* Массив пользователей */

void UserList::resize(int newLength){ // изменение размера объекта массива пользователей
    User* _userlisttemp{ new User[newLength] }; // временный массив
    if(_length > 0){
        int elementsToCopy{ (newLength > _length) ? _length : newLength };
        std::copy_n(_userlist, elementsToCopy, _userlisttemp); // копирование элементов
        delete[] _userlist; // удаление старого массива
        _userlist = _userlisttemp; // новый массив вместо старого(имя старого указывает на новый)
        _length = newLength;
    }
}
	
void UserList::showUsers(){ // вывод списка пользователей
	for(int i = 0; i < _length; i++){
		_userlist[i].getUser();
	}
}

int UserList::getLength(){ // возврат количества пользователей (равно размеру массива)
	return _length;
}

/* Cообщения */

void UserList::saveMsg(int _i, int _ir, std::string _m){ // сохранение сообщений
	if(_ir < 0){
		resizeMsgList(_count + 1); // групповые сообщения
		_groupmsg[_count - 1] = Msg(_userlist[_i].getLogin(), std::string("all"), _m);
	}
	else{
		resizeMsgList(_count + 1); // личка
		_groupmsg[_count - 1] = Msg(_userlist[_i].getLogin(), _userlist[_ir].getLogin(), _m);
	}
}

void UserList::getMsgs(int _i, int _ir){ // вывод истории сообщений
	if(_ir < 0){
		for(int i = 0; i < _count; i++){ // групповые сообщения
			_groupmsg[i].getGroup();
		}
	}
	else{
		for(int i = 0; i < _count; i++){ // личка
			_groupmsg[i].getPrivate(_userlist[_i].getLogin(), _userlist[_ir].getLogin());
		}
	}
}

void UserList::resizeMsgList(int newCount){ // изменение размера объекта массива сообщений
    Msg* _groupmsgtemp{ new Msg[newCount] }; // создаем временный массив
    if(_count > 0){
        int elementsToCopy{ (newCount > _count) ? _count : newCount };
        std::copy_n(_groupmsg, elementsToCopy, _groupmsgtemp); // копируем эл
        delete[] _groupmsg; // удаляем старый массив
        _groupmsg = _groupmsgtemp; // используем новый массив вместо старого; имя старого указывает на новый
        _count = newCount;
    }
}
