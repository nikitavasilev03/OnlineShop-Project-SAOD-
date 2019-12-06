#include "ProductBuilder.h"


shared_ptr<Entity> ProductBuilder::Create() {
	return CreateFromInputStream();
}

shared_ptr<Entity> ProductBuilder::CreateFromInputStream() {
	string name, sprice, siom;
	int price;
	int iuom;
	MeasurementType uom;
	
	cout << "�������� ������ ��������" << endl;

	cout << "������� ���: ";
	getline(cin, name);

	cout << "������� ����: ";
	getline(cin, sprice);
	istringstream str_to_price(sprice);
	str_to_price >> price;
	
	if (str_to_price.fail()) {
		cout << "�� ��������� ����" << endl;
		return NULL;
	}
	
	if (price < 0)
	{
		cout << "�� ��������� ����(����)" << endl;
		return NULL;
	}

	cout << "������� ������� ��������� (����� = 0, ���������� = 1, ����� = 2): ";
	getline(cin, siom);
	istringstream str_to_iuom(siom);
	str_to_iuom >> iuom;
	if (str_to_iuom.fail()) {
		cout << "�� ��������� ����" << endl;
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
		cout << "�� ��������� ���� (������� ���������)" << endl;
		return NULL;
		break;
	}
	return (shared_ptr<Entity>)(new Product(name, price, uom));
}