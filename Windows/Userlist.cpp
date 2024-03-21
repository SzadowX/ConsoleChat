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
	system("clear");
	std::cout << "---------- Регистрация нового пользователя ----------\n[q]uit для отмены\nЛогин и пароль не должны содержать пробелов\n";
	while(true){
		bool available{false}; // доступность логина
		std::cout << "\nВведите логин: ";
		std::string _l{}, _p{}, _n{}; // переменные для ввода логина и пароля
		std::cin >> _l;
		std::cin.ignore(256, '\n'); // игнорированиес слова после первого
				
		if(_l == "q"){ // отмена вызова
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
			std::cin.ignore(256, '\n'); // игнорирование ввода символов после первого

			std::cout << "Введите имя пользователя: ";
			std::getline(std::cin, _n); // ввод
			
			resize(_length + 1); // увеличение массива пользователей
			_userlist[_length - 1] = User(_l, _p, _n); // создание нового объекта пользователя 
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
		std::cout << "У вас осталось " << attempts << " попытки (для выхода введите q)\n";
		std::cout << "Логин: ";
		std::cin >> _l;
		std::cin.ignore(256, '\n'); // игнорирование слов после первого
		
		if(_l == "q"){ // отмена вызова
			system("cls");
			std::cout << "----- Отмена авторизации\n" << std::endl;
			attempts = -1; // выход из цикла при отмене авторизации
			break;
		}
		
		std::cout << "Пароль: ";
		std::cin >> _p;
		std::cin.ignore(256, '\n'); // игнорирование слов после первого
			
		if(authCheck(_l, _p)){
			attempts = -1; // выход из цикла при успешной авторизации
			i = getIndex(_l);
			system("cls");
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
		std::cout << "Введите имя собеседника:\n----------\nall\t(общий диалог)\n";
		showUsers(); // список диалогов (пользователей)
		std::cout << "----------\n";
		std::cout << _l << ": "; // имя отправителя
		std::string c;
		std::cin >> c; // имя получателя
		std::cin.ignore(); // игнорирование символа после cin, чтобы getline не считывал пустое значение
		int ir; // индекс получателя
		
		if(c == "q"){ // выход из цикла (пользователя из системы)
			system("cls");
			logOut<int>(i); // вызов выхода пользователя
			std::cout << "----- Пользователь вышел из чата!\n" << std::endl;
		}
		else if(c == "all"){ // переход в групповой чат
			system("cls");
			ir = -1;
			std::cout << "---------- Общий диалог ----------" << std::endl;
			getMsgs(i, ir);
			userTyping(i, ir);
		}
		else{ // переход в лс
			system("cls");
			ir = getIndex(c); // индекс получателя
			if(ir >= 0){
				if(i == ir){
					std::cout << "---------- Сохраненные сообщения ----------" << std::endl;
				}
				else{
					std::cout << "---------- Собеседник  " << _userlist[ir].getLogin() << " ----------" << std::endl; 
				}
				getMsgs(i, ir);
				userTyping(i, ir);
			}
		}
	}
}

template<typename T> void UserList::logOut(T n){ // выход пользователя из чата
	_userlist[n].setStatus(false);
}

void UserList::userTyping(int i, int j){ // блок ввода сообщений
	while(_userlist[i].getStatus()){
		std::string msg_body; // тело сообщения
		std::cout << _userlist[i].getLogin() << ": "; // имя отправителя
		std::getline(std::cin, msg_body); // ввод

		if(msg_body == "q"){ // выход из цикла (диалога)
			std::cout << "----- Пользователь вышел из диалога!\n" << std::endl;
			system("cls");
			break;
		}
		else{
			saveMsg(i, j, msg_body); // сообщения в формате адресант:адресат:сообщения
		}
	}
}

/* Массив пользователей */

void UserList::resize(int newLength){ // изменение размера объекта массива пользователей
    if(newLength < 0){ std::cout << "Неверное значение размера массива!" << std::endl; } // ошибка размера массива
    if(newLength == _length){ return; } // если соответствует нужному размеру
    User* _userlisttemp{ new User[newLength] }; // временный массив
    if(_length > 0){ // увеличение размера массива
        int elementsToCopy{ (newLength > _length) ? _length : newLength }; // переменная для копирования
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
		_msglist[_count - 1] = Msg(_userlist[_i].getLogin(), std::string("all"), _m);
	}
	else{
		resizeMsgList(_count + 1); // личка
		_msglist[_count - 1] = Msg(_userlist[_i].getLogin(), _userlist[_ir].getLogin(), _m);
	}
}

void UserList::getMsgs(int _i, int _ir){ // вывод истории сообщений
	if(_ir < 0){
		for(int i = 0; i < _count; i++){ // групповые сообщения
			_msglist[i].getGroup();
		}
	}
	else{
		for(int i = 0; i < _count; i++){ // личка
			_msglist[i].getPrivate(_userlist[_i].getLogin(), _userlist[_ir].getLogin());
		}
	}
}

void UserList::resizeMsgList(int newCount){ // изменение размера объекта массива сообщений
    if(newCount < 0){ std::cout << "Неверное значение размера массива!" << std::endl; } // ошибка размера массива
    if(newCount == _count){ return; } // если соответствует нужному размеру
    Msg* _msglisttemp{ new Msg[newCount] }; // создаем временный массив
    if(_count > 0){ // увеличение размера массива
        int elementsToCopy{ (newCount > _count) ? _count : newCount };
        std::copy_n(_msglist, elementsToCopy, _msglisttemp); // копируем элемент
        delete[] _msglist; // удаляем старый массив
        _msglist = _msglisttemp; // используем новый массив вместо старого; имя старого указывает на новый
        _count = newCount;
    }
}
