#include "SaleBuilder.h"
shared_ptr<Entity> SaleBuilder::Create() {
	return CreateFromInputStream();
}

shared_ptr<Entity> SaleBuilder::CreateFromInputStream() {
	int product_id, client_id, pcount;
	string s_product_id, s_client_id, s_date_sale, s_date_delivery, s_pcount;

	cout << "-----Создание новой продажи-----" << endl;

	cout << "Введите id продукта: ";
	s_product_id = input(cin);
	istringstream is_product_id(s_product_id);
	is_product_id >> product_id;
	if (is_product_id.fail()) {
		throw exception("Не коректный ввод");
	}

	cout << "Введите id клиента: ";
	s_client_id = input(cin);
	istringstream is_client_id(s_client_id);
	is_client_id >> client_id;
	if (is_client_id.fail()) {
		throw exception("Не коректный ввод");
	}

	cout << "Введите дату продажи: ";
	s_date_sale = input(cin);
	Date date_sale = DateFromString(s_date_sale);
	if (date_sale.year == -1)
	{
		throw exception("Не коректный ввод");
	}

	cout << "Введите дату доставки: ";
	s_date_delivery = input(cin);
	Date date_delivery = DateFromString(s_date_delivery);
	if (date_delivery.year == -1)
	{
		throw exception("Не коректный ввод");
	}

	cout << "Введите количество товара: ";
	s_pcount = input(cin);
	istringstream is_pcount(s_pcount);
	is_pcount >> pcount;
	if (is_pcount.fail()) {
		throw exception("Не коректный ввод");
	}

	return (shared_ptr<Sale>)(new Sale(product_id, client_id, date_sale, date_delivery, pcount));
}

shared_ptr<Entity> SaleBuilder::CreateEmpty() {
	return (shared_ptr<Entity>)(new Sale());
}