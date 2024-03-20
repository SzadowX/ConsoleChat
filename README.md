1.	Список участников команды:  
•	Иван Печий (lecheey);  
•	Павел Крючков (SzadowX);  
•	Георгий Чумарный (G1VC).  

3.	Описание выбранной идеи решения:
Основная идея - реализация  консольного чат-мессенджера со следующим  функционалом:
- регистрация пользователей (логин, пароль, имя);  
- вход в чат по логину/паролю;  
- отправка индивидуальных сообщений конкретному пользователю в личную беседу;  
- просмотр личных сообщений (для авторизованных пользователей);  
- обмен сообщениями между всеми пользователями в групповом чате;  
- две версии: Linux (системные функции) и Windows (системные функции, кодировка, локали).  

3.	Описание пользовательских  типов:  
class UserList // класс списка пользователей чата  
В нём были реализован следующий  ряд  методов и   функций:
- bool authCheck(std::string l, std::string p);
- int getIndex(std::string l); // возврат индекса пользователя по логину
- void setUser(); // создание нового пользователя
- void logIn(); // вход пользователя в систему
- template<typename T> void logOut(T n){ // выход пользователя из чата
- void userTyping(int i, int j); //  блок ввода сообщения 
/* массив пользователей */
- void resize(int newLength); // изменение размера объекта массива пользователей
- void showUsers(); // вывод списка пользователей
- int getLength(); // возврат количества пользователей (равно размеру массива)
/* сообщения */
- void saveMsg(int _i, int _ir, std::string _m);
- void getMsgs(int _i, int _ir);
- void resizeMsgList(int newCount); // изменение размера объекта массива сообщений  
class User // класс пользователя  
В нём были реализован следующий  ряд  методов и   функций:
- void getUser(); // вывод логина и пароля и статуса	
- string getLogin(); // возврат логина
- string getPass(); // возврат пароля
- setStatus(bool s); // изменение статуса
- bool getStatus(); // возврат статуса (системный)
- string statusInfo(); // возврат статуса (читабельный)

class Msg /* класс сообщений */  
В нём были реализован следующий  ряд  методов и   функций:  
- void getPrivate(std::string l, std::string r); // вывод личных сообщений
- void getGroup(); // вывод групповых сообщений};

4.	Роли: 

- Иван Печий: основная идея, базовый код, функции и классы, оптимизация под Linux.

- Павел Крючков: функции и классы, отладка, рефакторинг, оптимизация под Windows.

- Георий Чумарный: функции и классы, тестирование, оптимизация под Windows.
