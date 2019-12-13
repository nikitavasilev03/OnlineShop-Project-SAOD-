#include "ClientsData.h"

void ClientsData::Add(shared_ptr<Entity> item)  {
	if (item == NULL)
		return;
	if (item->GetID() == 0)
		item->SetID(NextID());
	ListData::Add(item);
}
void ClientsData::EditItem(Entity* new_item) {
	if (new_item == NULL)
		return;
	Client* client = (Client*)new_item;
	Client* item = (Client*)findById(client->GetID());
	if (item == NULL)
		throw exception("ProductData: Primory key not found");
	
	item->SetSecondName(client->GetSecondName());
	item->SetFirstName(client->GetFirstName());
	item->SetLastName(client->GetLastName());
	item->SetAddress(client->GetAddress());
	item->SetEmail(client->GetEmail());
	item->SetPhone(client->GetPhone());
	item->SetRegularClient(client->IsRegularClient());
	item->SetTotalPay(client->GetTotalMoney());
}