#include <iostream>
#include <string>
#include <algorithm> // для std::copy_n
#include "Userlist.h"

bool UserList::authCheck(std::string l, std::string p){ // проверка логина и пароля - авторизация пользователя
	for(int i = 0; i < _length; i++)
	if(l == _userlist[i].getLogin()){
		if(p == _userlist[i].getPass()){
			std::cout << "пользователь " << l << " вошёл в чат!" << std::endl;
			_userlist[i].setStatus(true);
			return true;
		}
		else{
			std::cout << "неверный логин или пароль! попробуйте ещё раз!" << std::endl;
			return false;
		}
	}

	return false;
}
	
void UserList::resize(int newLength){ // изменение размера объекта массива пользователей
    User* _userlisttemp{ new User[newLength] }; // создаем временный массив
    if(_length > 0){
        int elementsToCopy{ (newLength > _length) ? _length : newLength };
        std::copy_n(_userlist, elementsToCopy, _userlisttemp); // копируем эл
        delete[] _userlist; // удаляем старый массив
        _userlist = _userlisttemp; // используем новый массив вместо старого; имя старого указывает на новый
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

void UserList::GetChosenUser(int x){ // вызов метода класс пользователя
	_userlist[x].getUser();
}
	
void UserList::setUser(){ // создание нового пользователя
	while(true){
		bool available; // доступность логина
		std::string _l{}, _p{}; // переменные для ввода логина и пароля
		std::cout << "Введите логин: ";
		std::cin >> _l;
				
		if(_l == "quit"){ // опция вызода
			available = false;
			std::cout << "Отмена!" << std::endl;
			break;
		}
		
		// проверка наличия логина в системе

		for(int i = 0; i < _length; i++){
			if(_l == _userlist[i].getLogin()){
				std::cout << "Логин занят, выберите другой логин!" << std::endl;
				available = false;
			}
			else{
				available = true;
			}
		}
			
		if(available){
			std::cout << "Введите пароль:  ";
			std::cin >> _p;
			resize(_length + 1);
			_userlist[_length - 1] = User(_l, _p, false);
			std::cout << "Пользователь " << _l << " успешно зарегистрирован" << std::endl;
			break;
		}
	}
}

void UserList::logIn(){ // вход пользователя в систему
	int attempts = 3; // количество потыток входа(в данном случае 3)
	while(attempts > 0){
		std::string _l{}, _p{};
		std::cout << "Введите логин и пароль (у вас осталось " << attempts << " попытки): ";
		std::cin >> _l >> _p;
		
		if(authCheck(_l, _p)){
			attempts = -1; // разрыв цикла
			std::cin.ignore(); // игнорирование символа после cin, чтобы getline не считывал пустое значение
		}
		else{
			attempts--;
		}
	}

	if(attempts == 0){
		std:: cout << "Превышел лимит попыток! Повторите позже!" << std::endl;
	}
	
	for(int i = 0; i < _length; i++){ // переход в режим ввода сообщений пользователем
		while(_userlist[i].getStatus()){
//			_userlist[i].userTyping();
			std::string msg_body;
			std::cout << _userlist[i].getLogin() << ": ";
			std::getline(std::cin, msg_body);

			if(msg_body == "quit"){
				std::cout << "Пользователь вышел из чата" << std::endl;
				logOut(i);
			}	
			else{
				addMsg(_userlist[i].getLogin(), msg_body);
			}
		}
	}
}

void UserList::logOut(int n){ // выход пользователя из чата
	_userlist[n].setStatus(false);
}

void UserList::addMsg(std::string l, std::string m){
	resizeMsgList(_count + 1);
	_msglist[_count - 1] = Msg(l, m);
}

void UserList::getMsgs(){
	for(int i = 0; i < _count; i++){
		_msglist[i].showMsg();
	}
}

void UserList::resizeMsgList(int newCount){ // изменение размера объекта массива пользователей
    Msg* _msglisttemp{ new Msg[newCount] }; // создаем временный массив
    if(_count > 0){
        int elementsToCopy{ (newCount > _count) ? _count : newCount };
        std::copy_n(_msglist, elementsToCopy, _msglisttemp); // копируем эл
        delete[] _msglist; // удаляем старый массив
        _msglist = _msglisttemp; // используем новый массив вместо старого; имя старого указывает на новый
        _count = newCount;
    }
}
