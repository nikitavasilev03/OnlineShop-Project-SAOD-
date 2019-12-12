#include "ProductBuilder.h"

shared_ptr<Entity> ProductBuilder::Create() {
	return CreateFromInputStream();
}

shared_ptr<Entity> ProductBuilder::CreateFromInputStream() {
	string name, sprice, siom;
	int price;
	int iuom;
	
	cout << "-----Создание нового продукта-----" << endl;

	cout << "Введите имя: ";
	name = input(cin);
	if (name == "") {
		throw exception("Не коректный ввод");
	}

	cout << "Введите цену: ";
	sprice = input(cin);
	istringstream str_to_price(sprice);
	str_to_price >> price;
	
	if (str_to_price.fail()) {
		throw exception("Не коректный ввод");
	}
	if (price < 0)
	{
		throw exception("Не коректный ввод");
	}

	cout << "Введите единицу измерения (Штуки = 0, Килограммы = 1, Литры = 2): ";
	siom = input(cin);
	istringstream str_to_iuom(siom);
	str_to_iuom >> iuom;
	if (str_to_iuom.fail()) {
		throw exception("Не коректный ввод");
	}
	if (iuom < 0 || iuom > 2) {
		throw exception("Не коректный ввод");
	}

	return (shared_ptr<Entity>)(new Product(name, price, (MeasurementType)iuom));
}

shared_ptr<Entity> ProductBuilder::CreateEmpty() {
	return (shared_ptr<Entity>)(new Product());
}