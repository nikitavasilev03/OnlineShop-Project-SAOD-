#include "Sale.h"

Sale::Sale() : Entity(), date_sale(0, 0, 0), date_delivery(0, 0, 0) {
	product_id = 0;
	client_id = 0;
	pcount = 0;
	summary_pay = 0;
}

Sale::Sale(int _product_id, int _client_id, Date _date_sale, Date _date_delivery, int _count) : Entity(), date_sale(_date_sale), date_delivery(_date_delivery) {
	product_id = _product_id;
	client_id = _client_id;
	pcount = _count;
	summary_pay = 0;
}

Sale::Sale(int id, int _product_id, int _client_id, Date _date_sale, Date _date_delivery, int _count) : Entity(id), date_sale(_date_sale), date_delivery(_date_delivery) {
	product_id = _product_id;
	client_id = _client_id;
	pcount = _count;
	summary_pay = 0;
}

int Sale::GetProductID() {
	return product_id;
}
int Sale::GetClientID() {
	return client_id;
}
Date Sale::GetDateSale() {
	return date_sale;
}
Date Sale::GetDateDelivery() {
	return date_delivery;
}
int Sale::GetCount() {
	return pcount;
}
int Sale::GetSummatyPay() {
	return summary_pay;
}

void Sale::SetProductID(int id) {
	this->product_id = id;
}
void Sale::SetClientID(int id) {
	this->client_id = id;
}
void Sale::SetDateSale(Date date) {
	this->date_sale = date;
}
void Sale::SetDateDelivery(Date date) {
	this->date_delivery = date;
}
void Sale::SetCount(int _count) {
	this->pcount = _count;
}
void Sale::SetSummaryPay(int pay) {
	summary_pay = pay;
}

string Sale::ToString() {
	return 
		"ID: " + to_string(GetID()) + ",  " +
		"Product ID: " + to_string(product_id) + ",  " +
		"Client ID: " + to_string(client_id) + ",  " +
		"Date sale: " + DateToString(date_sale) + ",  " +
		"Date delivery: " + DateToString(date_delivery) + ",  " +
		"Count: " + to_string(pcount) + ",  " +
		"Total price: " + to_string(summary_pay);
}