#pragma once

#include "ListData.h"
#include "Client.h"

class ClientData : public ListData
{
private:

public:
	void Add(shared_ptr<Entity> item) override {
		if (item->GetID() == 0)
			item->SetID(NextID());
		ListData::Add(item);
	}
};

