#pragma once

#define TABLES_H

#include "ProductsData.h"
#include "ClientsData.h"
#include "SalesData.h"

class Tables
{
private:
	static void AddToData(Product* product, shared_ptr<Entity> entity);
	static void AddToData(Client* client, shared_ptr<Entity> entity);
	static void AddToData(Sale* sale, shared_ptr<Entity> entity);

	static void EditItem(Product* product, shared_ptr<Entity> entity);
	static void EditItem(Client* client, shared_ptr<Entity> entity);
	static void EditItem(Sale* sale, shared_ptr<Entity> entity);

public:
	static void AddToData(shared_ptr<Entity> entity);
	static void EditItem(shared_ptr<Entity> new_item);
	static shared_ptr<ProductsData> products;
	static shared_ptr<ClientsData> clients;
	static shared_ptr<SalesData> sales;
};