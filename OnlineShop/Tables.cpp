#include "Tables.h"

shared_ptr<ProductsData> Tables::products = (shared_ptr<ProductsData>)(new ProductsData());
shared_ptr<ClientsData> Tables::clients = (shared_ptr<ClientsData>)(new ClientsData());
shared_ptr<SalesData> Tables::sales = (shared_ptr<SalesData>)(new SalesData());

void Tables::AddToItem(shared_ptr<Entity> entity) {
	Entity* ent = entity->GetEntity();
	Product* product = dynamic_cast<Product*>(ent);
	Client* client = dynamic_cast<Client*>(ent);
	Sale* sale = dynamic_cast<Sale*>(ent);

	if (product)
		AddToItem(product, entity);
	else if (client)
		AddToItem(client, entity);
	else if (sale)
		AddToItem(sale, entity);
	else
		throw exception("");
}
void Tables::EditItem(shared_ptr<Entity> entity) {
	Entity* ent = entity->GetEntity();
	Product* product = dynamic_cast<Product*>(ent);
	Client* client = dynamic_cast<Client*>(ent);
	Sale* sale = dynamic_cast<Sale*>(ent);

	if (product)
		EditItem(product, entity);
	else if (client)
		EditItem(client, entity);
	else if (sale)
		EditItem(sale, entity);
	else
		throw exception("");
}
void Tables::RemoveItem(shared_ptr<Entity> entity) {
	Entity* ent = entity->GetEntity();
	Product* product = dynamic_cast<Product*>(ent);
	Client* client = dynamic_cast<Client*>(ent);
	Sale* sale = dynamic_cast<Sale*>(ent);

	if (product)
		RemoveItem(product, entity);
	else if (client)
		RemoveItem(client, entity);
	else if (sale)
		RemoveItem(sale, entity);
	else
		throw exception("");
}

//AddItem
void Tables::AddToItem(Product* product, shared_ptr<Entity> entity) {
	products->Add(entity);
}
void Tables::AddToItem(Client* client, shared_ptr<Entity> entity) {
	clients->Add(entity);
}
void Tables::AddToItem(Sale* sale, shared_ptr<Entity> entity) {
	Entity* ent_product = products->findById(sale->GetProductID());
	Entity* ent_client = clients->findById(sale->GetClientID());
	if (ent_product && ent_client) {
		Product* product = (Product*)ent_product;
		Client* client = (Client*)ent_client;
		if (client->IsRegularClient())
			sale->SetSummaryPay(sale->GetCount() * product->GetPrice() / 100 * 98);
		else
			sale->SetSummaryPay(sale->GetCount() * product->GetPrice());
		client->IncTotalMoney(sale->GetSummatyPay());
		if (client->GetTotalMoney() >= client->TOTAL_PAY_FOR_REGULAR_CLIENT)
			client->SetRegularClient();
		sales->Add(entity);
	}
	else
		throw exception("No foreign key matches");
}

//EditItem
void Tables::EditItem(Product* product, shared_ptr<Entity> entity) {
	products->EditItem(product);
}
void Tables::EditItem(Client* client, shared_ptr<Entity> entity) {
	clients->EditItem(client);
}
void Tables::EditItem(Sale* sale, shared_ptr<Entity> entity) {
	Entity* ent_product = products->findById(sale->GetProductID());
	Entity* ent_client = clients->findById(sale->GetClientID());
	if (ent_product && ent_client) {
		sales->EditItem(sale);
	}
	else
		throw exception("No foreign key matches");
}

//RemoveItem
void Tables::RemoveItem(Product* product, shared_ptr<Entity> entity) {
	for (auto ent_sale : *sales->GetItems())
	{
		Sale* sale = (Sale*)ent_sale->GetEntity();
		if (sale->GetProductID() == product->GetID()) {
			throw exception("Error! This object refers to sale", sale->GetID());
		}
	}
	products->Remove(product->GetID());
}
void Tables::RemoveItem(Client* client, shared_ptr<Entity> entity) {
	for (auto ent_sale : *sales->GetItems())
	{
		Sale* sale = (Sale*)ent_sale->GetEntity();
		if (sale->GetClientID() == client->GetID()) {
			throw exception("Error! This object refers to sale", sale->GetID());
		}
	}
	clients->Remove(client->GetID());
}
void Tables::RemoveItem(Sale* sale, shared_ptr<Entity> entity) {
	Entity* ent_sale = sales->findById(sale->GetID());
	if (ent_sale) {
		Sale* cur_sale = (Sale*)ent_sale;
		Entity* ent_client = clients->findById(cur_sale->GetClientID());
		if (ent_client) {
			Client* client = (Client*)ent_client;
			client->IncTotalMoney(-cur_sale->GetSummatyPay());
			if (client->GetTotalMoney() < client->TOTAL_PAY_FOR_REGULAR_CLIENT)
				client->SetRegularClient(false);
		}
		sales->Remove(sale->GetID());
	}
	else
	{
		throw exception("Error! Not found sale");
	}
	
}