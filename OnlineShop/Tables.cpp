#include "Tables.h"

shared_ptr<ProductsData> Tables::products = (shared_ptr<ProductsData>)(new ProductsData());
shared_ptr<ClientsData> Tables::clients = (shared_ptr<ClientsData>)(new ClientsData());
shared_ptr<SalesData> Tables::sales = (shared_ptr<SalesData>)(new SalesData());

void Tables::AddToData(shared_ptr<Entity> entity) {
	Entity* ent = entity->GetEntity();
	Product* product = dynamic_cast<Product*>(ent);
	Client* client = dynamic_cast<Client*>(ent);
	Sale* sale = dynamic_cast<Sale*>(ent);

	if (product)
		AddToData(product, entity);
	else if (client)
		AddToData(client, entity);
	else if (sale)
		AddToData(sale, entity);
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

void Tables::AddToData(Product* product, shared_ptr<Entity> entity) {
	products->Add(entity);
}
void Tables::AddToData(Client* client, shared_ptr<Entity> entity) {
	clients->Add(entity);
}
void Tables::AddToData(Sale* sale, shared_ptr<Entity> entity) {
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

