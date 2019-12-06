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

	cout << "�������� ������ �������" << endl;

	cout << "������� ������� (��� ������������ ����): ";
	getline(cin, second_name);
	if (second_name == "") {
		cout << "�� ��������� ����" << endl;
		return NULL;
	}

	cout << "������� ��� (��� ������������ ����): ";
	getline(cin, first_name);
	if (first_name == "") {
		cout << "�� ��������� ����" << endl;
		return NULL;
	}

	cout << "������� ��������: ";
	getline(cin, last_name);

	cout << "������� E-mail (��� ������������ ����): ";
	getline(cin, email);
	if (email == "") {
		cout << "�� ��������� ����" << endl;
		return NULL;
	}

	cout << "������� �������: ";
	getline(cin, phone);

	cout << "������� �����: ";
	getline(cin, address);

	return  (shared_ptr<Entity>)(new Client(second_name, first_name, email, last_name, address, phone));
}