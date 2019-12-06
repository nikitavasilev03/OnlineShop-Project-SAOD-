#pragma once

#include "Entity.h"

class EntityBuilder
{
public:
	virtual shared_ptr<Entity> Create() = 0;
};

