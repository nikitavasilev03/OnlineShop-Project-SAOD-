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

	cout << "-----Создание нового клиента-----" << endl;

	cout << "Введите фамилию (это обязательное поле): ";
	second_name = input(cin);
	if (second_name == "") {
		throw exception("Не коректный ввод");
	}

	cout << "Введите имя (это обязательное поле): ";
	first_name = input(cin);
	if (first_name == "") {
		throw exception("Не коректный ввод");
	}

	cout << "Введите отчество: ";
	last_name = input(cin);

	cout << "Введите E-mail (это обязательное поле): ";
	email = input(cin);
	if (email == "") {
		throw exception("Не коректный ввод");
	}

	cout << "Введите телефон: ";
	phone = input(cin);
	cout << "Введите адрес: ";
	address = input(cin);
	return  (shared_ptr<Entity>)(new Client(second_name, first_name, email, last_name, address, phone));
}

shared_ptr<Entity> ClientBuilder::CreateEmpty() {
	return (shared_ptr<Entity>)(new Client());
}