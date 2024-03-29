#pragma once
#include "EntityBuilder.h"
#include "System.h"
#include "Sale.h"

class SaleBuilder : public EntityBuilder
{
	shared_ptr<Entity> Create() override;
	shared_ptr<Entity> CreateFromInputStream();
};

