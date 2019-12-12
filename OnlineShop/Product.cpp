#include "Product.h"

Product::Product() : Entity() {
	name = "";
	price = 0;
	uom = Counts;
}

Product::Product(string name, int price, MeasurementType uom) : Entity() {
	this->name = name;
	this->price = price;
	this->uom = uom;
}

Product::Product(int id, string name, int price, MeasurementType uom) : Entity(id) {
	this->name = name;
	this->price = price;
	this->uom = uom;
}


string Product::GetName() {
	return name;
}
void Product::SetName(string new_name) {
	name = new_name;
}
int Product::GetPrice() {
	return price;
}
void Product::SetPrice(int new_price) {
	price = new_price;
}
MeasurementType Product::GetUOM() {
	return uom;
}
void Product::SetUOM(MeasurementType new_uom) {
	uom = new_uom;
}

string Product::ToString() {
	string str_uom;
	switch (uom)
	{
	case Counts:
		str_uom = "Counts";
		break;
	case Kilograms:
		str_uom = "Kilograms";
		break;
	case Liters:
		str_uom = "Liters";
		break;
	default:
		break;
	}
	return 
		"ID: " + to_string(GetID()) +  ",  " + 
		"Name: " + name + ",  " + 
		"Price: " + to_string(price) + ",  " + 
		"UOM: " + str_uom;
}