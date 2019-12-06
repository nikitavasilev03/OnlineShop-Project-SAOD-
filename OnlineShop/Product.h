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
	void SetName(string new_name);
	int GetPrice();
	void SetPrice(int new_price);
	MeasurementType GetUOM();
	void SetUOM(MeasurementType new_uom);
	
	string ToString() override;
};

