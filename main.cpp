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
	User(int length) : _length(length) {
		_userList = new std::string[_length]{};
	}
	User(std::string login, int pass) : _login(login), _pass(pass){};
//	~User(){
//		delete[] _userList;
//	}

	void Show(){
		std::cout << _login << " " << _pass << std::endl;
	}
};

int main(){
	User* list[10];	
	int userCount = 0;

	std::string login;
	int pass;
	
	bool a = true;

	while(a){
		char choice;
		std::cout << "добавить пользователя? " << std::endl;
		std::cin >> choice;
		switch (choice){
			case 'y':
				userCount += 1;
				std::cout << "Придумайте логин и пароль: " << std::endl;
				std::cin >> login >> pass;
				list[userCount - 1] = new User(login, pass);
				break;
			case 'n':
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
