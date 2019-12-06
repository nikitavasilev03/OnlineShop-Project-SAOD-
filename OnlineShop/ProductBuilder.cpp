#include "ProductBuilder.h"


shared_ptr<Entity> ProductBuilder::Create() {
	return CreateFromInputStream();
}

shared_ptr<Entity> ProductBuilder::CreateFromInputStream() {
	string name, sprice, siom;
	int price;
	int iuom;
	MeasurementType uom;
	
	cout << "Создание нового продукта" << endl;

	cout << "Введите имя: ";
	getline(cin, name);

	cout << "Введите цену: ";
	getline(cin, sprice);
	istringstream str_to_price(sprice);
	str_to_price >> price;
	
	if (str_to_price.fail()) {
		cout << "Не коректный ввод" << endl;
		return NULL;
	}
	
	if (price < 0)
	{
		cout << "Не коректный ввод(цена)" << endl;
		return NULL;
	}

	cout << "Введите единицу измерения (Штуки = 0, Килограммы = 1, Литры = 2): ";
	getline(cin, siom);
	istringstream str_to_iuom(siom);
	str_to_iuom >> iuom;
	if (str_to_iuom.fail()) {
		cout << "Не коректный ввод" << endl;
		return NULL;
	}
	switch (iuom)
	{
	case 0:
		uom = Counts;
		break;
	case 1:
		uom = Kilograms;
		break;
	case 2:
		uom = Liters;
		break;
	default:
		cout << "Не коректный ввод (единицы измерения)" << endl;
		return NULL;
		break;
	}
	return (shared_ptr<Entity>)(new Product(name, price, uom));
}