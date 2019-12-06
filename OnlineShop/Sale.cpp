#include "Sale.h"



Sale::Sale(int _product_id, int _client_id, Date _date_sale, Date _date_delivery, int _count) : Entity(), date_sale(_date_sale), date_delivery(_date_delivery) {
	product_id = _product_id;
	client_id = _client_id;
	pcount = _count;
}

Sale::Sale(int id, int _product_id, int _client_id, Date _date_sale, Date _date_delivery, int _count) : Entity(id), date_sale(_date_sale), date_delivery(_date_delivery) {
	product_id = _product_id;
	client_id = _client_id;
	pcount = _count;
}

int Sale::GetProductID() {
	return product_id;
}

int Sale::GetClientID() {
	return client_id;
}

string Sale::ToString() {
	return to_string(GetID()) + " " +
		to_string(product_id) + " " +
		to_string(client_id) + " " +
		System::DateToString(date_sale) + " " +
		System::DateToString(date_delivery) + " " +
		to_string(pcount);
}