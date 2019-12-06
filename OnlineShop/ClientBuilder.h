#pragma once
#include "EntityBuilder.h"
#include "Client.h"
class ClientBuilder : public EntityBuilder
{
public:
	shared_ptr<Entity> Create() override;
	shared_ptr<Entity> CreateFromInputStream();
};

