#pragma once

#include "EntityBuilder.h"
#include "Sale.h"

class SaleBuilder : public EntityBuilder
{
	shared_ptr<Entity> Create() override;
	shared_ptr<Entity> CreateEmpty() override;
	shared_ptr<Entity> CreateFromInputStream();
};

