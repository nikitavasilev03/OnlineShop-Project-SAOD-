#pragma once

#include "Entity.h"
#include "Environment.h"

class EntityBuilder
{
public:
	virtual shared_ptr<Entity> Create() = 0;
	virtual shared_ptr<Entity> CreateEmpty() = 0;
};

