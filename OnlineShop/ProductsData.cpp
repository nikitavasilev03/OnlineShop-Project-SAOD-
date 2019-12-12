#include "ProductsData.h"

void ProductsData::Add(shared_ptr<Entity> item) {
	if (item == NULL)
		return;
	if (item->GetID() == 0)
		item->SetID(NextID());
	ListData::Add(item);
}
void ProductsData::EditItem(Entity* new_item) {
	if (new_item == NULL)
		return;
	Product* product = (Product*)new_item;
	Product* item  = (Product*)findById(product->GetID());
	if (item == NULL)
		throw exception("ProductData: Primory key not found");
	item->SetName(product->GetName());
	item->SetPrice(product->GetPrice());
	item->SetUOM(product->GetUOM());
}