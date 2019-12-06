#include "ClientBuilder.h"

shared_ptr<Entity> ClientBuilder::Create() {
	return CreateFromInputStream();
}
shared_ptr<Entity> ClientBuilder::CreateFromInputStream() {
	string second_name;
	string first_name;
	string last_name;
	string address;
	string phone;
	string email;

	cout << "Создание нового клиента" << endl;

	cout << "Введите фамилию (это обязательное поле): ";
	getline(cin, second_name);
	if (second_name == "") {
		cout << "Не коректный ввод" << endl;
		return NULL;
	}

	cout << "Введите имя (это обязательное поле): ";
	getline(cin, first_name);
	if (first_name == "") {
		cout << "Не коректный ввод" << endl;
		return NULL;
	}

	cout << "Введите отчество: ";
	getline(cin, last_name);

	cout << "Введите E-mail (это обязательное поле): ";
	getline(cin, email);
	if (email == "") {
		cout << "Не коректный ввод" << endl;
		return NULL;
	}

	cout << "Введите телефон: ";
	getline(cin, phone);

	cout << "Введите адрес: ";
	getline(cin, address);

	return  (shared_ptr<Entity>)(new Client(second_name, first_name, email, last_name, address, phone));
}