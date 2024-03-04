#include <iostream>
#include <string>

class User{
protected:
	std::string _login;
	int _pass;
//	std::string _name;
	int _length;
	std::string* _userList{};
public:
	User() = default;
	User(std::string login, int pass) : _login(login), _pass(pass){};

//	User(int length) : _length(length) {
//		_userList = new std::string[_length]{};
//	}
//	~User(){
//		delete[] _userList;
//	}

	void Show(){
		std::cout << _login << " " << _pass << std::endl;
	}

	bool AuthCheck(std::string l, int p){
		if(l == this->_login && p == this->_pass){
			return true;
		}
		else{
			return false;
		}
	}

//	Add(){}
	
	std::string userName(){
		return this->_login;
	}
};

int main(){
	User* list[10];	// массив объектов пользователей
	int userCount = 0; // счетчик зарегистрированных пользователей

	bool a = true;
	
	std::cout << "Добро пожаловать в чат" << std::endl;

	while(a){
		std::cout << "Для работы с программой исппользуйте:\n[a]dd для регистрации нового пользователя\n[l]ogin для входа в аккаунт\n[q]uitдля выхода из аккаунта" << std::endl;
		
		std::string login; // логин
		int pass; // пароль
	
		char choice;

		std::cin >> choice;
		switch (choice){
			case 'a':
				userCount += 1;
				std::cout << "Придумайте логин и пароль: " << std::endl;
				std::cin >> login >> pass;
				list[userCount - 1] = new User(login, pass);
				std::cout << "Пользователь успешно зарегистрирован" << std::endl;
				break;
			case 'l':
				std::cout << "Ведидите логин и пароль: ";

				std::cin >> login >> pass;

				for(int i = 0; i < userCount; i++){
					if(list[i]->AuthCheck(login, pass)){
						std::cout << "Добро пожаловать " << list[i]->userName() << std::endl;
						while(true){
							std::cout << list[i]->userName() << ": ";
							std::string msg_body;
							std::getline(std::cin, msg_body);
//							if(msg_body[0] == "quit"){
								break;
//							}
						}
					}
					else{
						std::cout << "Пользователь не зарегистрирован в системе" << std::endl;
					}
				}
				break;

			case 'q':
				a = false;
				break;
			default:
				std::cout << "неверное значение" << std::endl;
				break;
		}
	}

	std::cout << "список пользователей:" << std::endl;
	for(int i = 0; i < userCount; i++){
		list[i]->Show();
	}
	
	for(int i = 0; i < userCount; i++){
		delete list[i];
	}

	return 0;
}
