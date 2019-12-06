#include "SaleBuilder.h"
shared_ptr<Entity> SaleBuilder::Create() {
	return CreateFromInputStream();
}

shared_ptr<Entity> SaleBuilder::CreateFromInputStream() {
	int product_id, client_id, pcount;
	string s_product_id, s_client_id, s_date_sale, s_date_delivery, s_pcount;

	cout << "�������� ����� �������" << endl;

	cout << "������� id ��������: ";
	getline(cin, s_product_id);
	istringstream is_product_id(s_product_id);
	is_product_id >> product_id;
	if (is_product_id.fail()) {
		cout << "�� ��������� ����" << endl;
		return NULL;
	}

	cout << "������� id �������: ";
	getline(cin, s_client_id);
	istringstream is_client_id(s_client_id);
	is_client_id >> client_id;
	if (is_client_id.fail()) {
		cout << "�� ��������� ����" << endl;
		return NULL;
	}

	cout << "������� ���� �������: ";
	getline(cin, s_date_sale);
	Date date_sale = System::DateFromString(s_date_sale);
	if (date_sale.year == -1)
	{
		cout << "�� ��������� ����" << endl;
		return NULL;
	}

	cout << "������� ���� ��������: ";
	getline(cin, s_date_delivery);
	Date date_delivery = System::DateFromString(s_date_delivery);
	if (date_delivery.year == -1)
	{
		cout << "�� ��������� ����" << endl;
		return NULL;
	}

	cout << "������� ���������� ������: ";
	getline(cin, s_pcount);
	istringstream is_pcount(s_pcount);
	is_pcount >> pcount;
	if (is_pcount.fail()) {
		cout << "�� ��������� ����" << endl;
		return NULL;
	}

	return (shared_ptr<Sale>)(new Sale(product_id, client_id, date_sale, date_delivery, pcount));
}