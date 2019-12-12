#pragma once

#define SYSTEM_H

#ifndef TABLES_H
	#include "Tables.h"
#endif // !Tables_H

#ifndef SHELL_H
	#include "Shell.h"
#endif // !SHELL_H

#include "ProductBuilder.h"
#include "ClientBuilder.h"
#include "SaleBuilder.h"

class System
{
private:

public:

	static void Start();
	static void Add(shared_ptr<EntityBuilder> entityBuilder);
	static void Remove(shared_ptr<ListData> listData, int id);
	static void Edit(shared_ptr<EntityBuilder> entityBuilder, int id);
	static void Print(shared_ptr<ListData> listData);
	static void Print(shared_ptr<ListData> listData, int id);
	static void SaveData();
	static void LoadData();

	static shared_ptr<ProductsData> GetProducts();
	static shared_ptr<ClientsData> GetClients();
	static shared_ptr<SalesData> GetSales();
};

