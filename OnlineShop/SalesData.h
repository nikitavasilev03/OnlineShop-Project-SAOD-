#pragma once

#include "ListData.h"
#include "Sale.h"

class SalesData : public ListData
{
public:
	void Add(shared_ptr<Entity> item) override;
	void EditItem(Entity* new_item) override;
};