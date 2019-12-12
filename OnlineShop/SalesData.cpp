#include "SalesData.h"

void SalesData::Add(shared_ptr<Entity> item) {
	if (item == NULL)
		return;
	if (item->GetID() == 0)
		item->SetID(NextID());
	ListData::Add(item);
}
void SalesData::EditItem(Entity* new_item) {
	if (new_item == NULL)
		return;
	Sale* sale = (Sale*)new_item;
	Sale* item = (Sale*)findById(sale->GetID());
	if (item == NULL)
		throw exception("ProductData: Primory key not found");
	
	item->SetProductID(sale->GetProductID());
	item->SetClientID(sale->GetClientID());
	item->SetDateSale(sale->GetDateSale());
	item->SetDateDelivery(sale->GetDateDelivery());
	item->SetCount(sale->GetCount());
	item->SetSummaryPay(sale->GetSummatyPay());
}
//int product_id;
//int client_id;
//Date date_sale;
//Date date_delivery;
//int pcount;
//int summary_pay;