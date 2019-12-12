#pragma once

#include "ListData.h"
#include "Client.h"

class ClientsData : public ListData
{
private:

public:
	void Add(shared_ptr<Entity> item) override;
	void EditItem(Entity* new_item) override;
};

