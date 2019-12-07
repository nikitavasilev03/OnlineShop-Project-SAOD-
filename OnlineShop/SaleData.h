#pragma once
#include "ListData.h"
#include "Client.h"
#include "Product.h"
#include "Sale.h"

class SaleData : public ListData
{
private:
public:
	void Add(shared_ptr<Entity> item) override {
		if (item == NULL)
			return;

		if (item->GetID() == 0)
			item->SetID(NextID());
		
		Sale* sale = (Sale*)&(*item);
		Product* product = NULL;
		for (auto i : *System::GetProducts()->GetItems())
		{
			if (item->GetID() == sale->GetProductID()) {
				product = (Product*)&(*i);
				break;
			}
		}

		Client* client = NULL;
		for (auto i : *System::GetClients()->GetItems())
		{
			if (item->GetID() == sale->GetClientID()) {
				client = (Client*)&(*i);
				break;
			}
		}

		if (client && product) {

			if (client->IsRegularClient())
				sale->SetSummaryPay(sale->GetCount() * product->GetPrice() / 100 * 98);
			else
				sale->SetSummaryPay(sale->GetCount() * product->GetPrice());

			client->IncTotalMoney(sale->GetSummatyPay());
			if (client->GetTotalMoney() >= client->TOTAL_PAY_FOR_REGULAR_CLIENT)
				client->SetRegularClient();

			ListData::Add(item);
		}
		else
		{
			throw exception("No foreign key matches");
		}
	}
};

