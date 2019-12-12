#include "SalesData.h"

void SalesData::Add(shared_ptr<Entity> item) {
	if (item == NULL)
		return;
	if (item->GetID() == 0)
		item->SetID(NextID());
	ListData::Add(item);
}