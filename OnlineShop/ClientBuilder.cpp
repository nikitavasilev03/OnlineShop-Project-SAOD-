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

	cout << "-----�������� ������ �������-----" << endl;

	cout << "������� ������� (��� ������������ ����): ";
	second_name = input(cin);
	if (second_name == "") {
		throw exception("�� ��������� ����");
	}

	cout << "������� ��� (��� ������������ ����): ";
	first_name = input(cin);
	if (first_name == "") {
		throw exception("�� ��������� ����");
	}

	cout << "������� ��������: ";
	last_name = input(cin);

	cout << "������� E-mail (��� ������������ ����): ";
	email = input(cin);
	if (email == "") {
		throw exception("�� ��������� ����");
	}

	cout << "������� �������: ";
	phone = input(cin);
	cout << "������� �����: ";
	address = input(cin);
	return  (shared_ptr<Entity>)(new Client(second_name, first_name, email, last_name, address, phone));
}

shared_ptr<Entity> ClientBuilder::CreateEmpty() {
	return (shared_ptr<Entity>)(new Client());
}