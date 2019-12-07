#pragma once

#include "ListData.h"
#include "Product.h"

class ProductData : public ListData
{
public:
	void Add(shared_ptr<Entity> item) override {
		if (item == NULL)
			return;
		if (item->GetID() == 0)
			item->SetID(NextID());
		ListData::Add(item);
	}
};

