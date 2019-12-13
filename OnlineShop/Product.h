#pragma once

#include "Entity.h"

enum MeasurementType
{
	Counts,
	Kilograms,
	Liters
};

class Product : public Entity
{
private:
	string name;
	int price;
	MeasurementType uom;
public:

	Product();
	Product(string name, int price, MeasurementType uom);
	Product(int id, string name, int price, MeasurementType uom);

	string GetName();
	int GetPrice();
	MeasurementType GetUOM();

	void SetName(string new_name);
	void SetPrice(int new_price);
	void SetUOM(MeasurementType new_uom);
	
	string ToString() override;
};

