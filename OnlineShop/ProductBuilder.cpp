#include "ProductBuilder.h"

shared_ptr<Entity> ProductBuilder::Create() {
	return CreateFromInputStream();
}

shared_ptr<Entity> ProductBuilder::CreateFromInputStream() {
	string name, sprice, siom;
	int price;
	int iuom;
	
	cout << "-----�������� ������ ��������-----" << endl;

	cout << "������� ���: ";
	name = input(cin);
	if (name == "") {
		throw exception("�� ��������� ����");
	}

	cout << "������� ����: ";
	sprice = input(cin);
	istringstream str_to_price(sprice);
	str_to_price >> price;
	
	if (str_to_price.fail()) {
		throw exception("�� ��������� ����");
	}
	if (price < 0)
	{
		throw exception("�� ��������� ����");
	}

	cout << "������� ������� ��������� (����� = 0, ���������� = 1, ����� = 2): ";
	siom = input(cin);
	istringstream str_to_iuom(siom);
	str_to_iuom >> iuom;
	if (str_to_iuom.fail()) {
		throw exception("�� ��������� ����");
	}
	if (iuom < 0 || iuom > 2) {
		throw exception("�� ��������� ����");
	}

	return (shared_ptr<Entity>)(new Product(name, price, (MeasurementType)iuom));
}

shared_ptr<Entity> ProductBuilder::CreateEmpty() {
	return (shared_ptr<Entity>)(new Product());
}