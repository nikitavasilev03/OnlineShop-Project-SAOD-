#pragma once

#include "Entity.h"
#include "EntityBuilder.h"
#include "Product.h"
#include "stdafx.h"

class ProductBuilder : public EntityBuilder
{
public:
	shared_ptr<Entity> Create() override;
	shared_ptr<Entity> CreateFromInputStream();
};

