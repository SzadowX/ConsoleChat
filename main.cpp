#include <iostream>

int main(){
	int rows = 5; // количество пользователей
	const int columns = 2; // pair user:password 

	std::string** usersList = new std::string*[rows]; // динамический двумерный массив
	for(int i = 0; i < rows; i++){
		usersList[i] = new std::string[columns];
	}
	
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			if(j == 0){
				usersList[i][j] = "login";
				std::cout << usersList[i][j] << " ";
			}
			else if(j == 1){
				usersList[i][j] = "pass";
				std::cout << usersList[i][j] << " ";
			}
		}
		std::cout << std::endl;
	}

	char a[20]; 
	std::string b;
	std::string c;

	std::cin.getline(a, 20);

	if(a[0] == 'a'){
		std::cout << "добавить" << std::endl;
	}
	else{
		std::cout << "John: " << a << b << c << std::endl;
	}

	return 0;
}
