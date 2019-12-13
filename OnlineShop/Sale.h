#pragma once

#include "Entity.h"
#include "Environment.h"

class Sale :
	public Entity
{
private:
	int product_id;
	int client_id;
	Date date_sale;
	Date date_delivery;
	int pcount;
	int total_price;
public:
	Sale();
	Sale(int _product_id, int _client_id, Date _date_sale, Date _date_delivery, int _count);
	Sale(int id, int _product_id, int _client_id, Date _date_sale, Date _date_delivery, int _count);

	int GetProductID();
	int GetClientID();
	Date GetDateSale();
	Date GetDateDelivery();
	int GetCount();
	int GetTotalPrice();

	void SetProductID(int id);
	void SetClientID(int id);
	void SetDateSale(Date date);
	void SetDateDelivery(Date date);
	void SetCount(int _count);
	void SetTotalPrice(int pay);

	string ToString() override;
};

