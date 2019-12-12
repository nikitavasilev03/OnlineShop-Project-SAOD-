#pragma once

#define TABLES_H

#include "ProductsData.h"
#include "ClientsData.h"
#include "SalesData.h"

class Tables
{
private:
	static void AddToItem(Product* product, shared_ptr<Entity> entity);
	static void AddToItem(Client* client, shared_ptr<Entity> entity);
	static void AddToItem(Sale* sale, shared_ptr<Entity> entity);

	static void EditItem(Product* product, shared_ptr<Entity> entity);
	static void EditItem(Client* client, shared_ptr<Entity> entity);
	static void EditItem(Sale* sale, shared_ptr<Entity> entity);

	static void RemoveItem(Product* product, shared_ptr<Entity> entity);
	static void RemoveItem(Client* client, shared_ptr<Entity> entity);
	static void RemoveItem(Sale* sale, shared_ptr<Entity> entity);

public:
	static void AddToItem(shared_ptr<Entity> entity);
	static void EditItem(shared_ptr<Entity> new_item);
	static void RemoveItem(shared_ptr<Entity> entity);
	static shared_ptr<ProductsData> products;
	static shared_ptr<ClientsData> clients;
	static shared_ptr<SalesData> sales;
};