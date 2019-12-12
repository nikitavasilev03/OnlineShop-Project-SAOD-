#pragma once

#include "EntityBuilder.h"
#include "Product.h"

class ProductBuilder : public EntityBuilder
{
public:
	shared_ptr<Entity> Create() override;
	shared_ptr<Entity> CreateEmpty() override;
	shared_ptr<Entity> CreateFromInputStream();
};

