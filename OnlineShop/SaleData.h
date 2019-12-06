#pragma once
#include "ListData.h"
#include "Client.h"
#include "Product.h"
#include "Sale.h"

class SaleData : public ListData
{
	void Add(shared_ptr<Entity> item) override {
		if (item->GetID() == 0)
			item->SetID(NextID());
		ListData::Add(item);

		Sale* sale = (Sale*)&(*item);
		Product* product = NULL;
		for (auto i : *System::GetProducts()->GetItems())
		{
			if (item->GetID() == sale->GetProductID()) {
				product = (Product*)&(*i);
				break;
			}
		}
		
	}
};

