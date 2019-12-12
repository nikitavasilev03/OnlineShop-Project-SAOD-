#pragma once

#include "ListData.h"
#include "Product.h"

class ProductsData : public ListData
{
public:
	void Add(shared_ptr<Entity> item) override;
	void EditItem(Entity* new_item) override;
};

