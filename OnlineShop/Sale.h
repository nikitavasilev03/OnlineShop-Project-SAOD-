#pragma once
#include "Entity.h"
#include "System.h"

class Sale : public Entity
{
private:
	int product_id;
	int client_id;
	Date date_sale;
	Date date_delivery;
	int pcount;
public:
	Sale(int _product_id, int _client_id, Date _date_sale, Date _date_delivery, int _count);
	Sale(int id, int _product_id, int _client_id, Date _date_sale, Date _date_delivery, int _count);

	int GetProductID();
	int GetClientID();

	string ToString() override;
};
