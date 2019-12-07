#pragma once

#include "ProductsData.h"
#include "ClientsData.h"
#include "SalesData.h"

#include "Shell.h"

#include "ProductBuilder.h"
#include "ClientBuilder.h"
#include "SaleBuilder.h"

#include "stdafx.h"

class System
{
private:
	static shared_ptr<ProductsData> products;
	static shared_ptr<ClientsData> clients;
	static shared_ptr<SalesData> sales;
public:

	static void Start();
	static void Add(shared_ptr<ListData> listData, shared_ptr<EntityBuilder> entityBuilder);
	static void Remove(shared_ptr<ListData> listData, int id);
	static void Edit(shared_ptr<ListData> listData, int id);
	static void Print(shared_ptr<ListData> listData);
	static void Print(shared_ptr<ListData> listData, int id);
	static void SaveData();
	static void LoadData();
	
	static Date DateFromString(string in_str);
	static string DateToString(Date in_date);

	static shared_ptr<ProductsData> GetProducts();
	static shared_ptr<ClientsData> GetClients();
	static shared_ptr<SalesData> GetSales();
};

