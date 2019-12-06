#pragma once

#include "ProductData.h"
#include "ClientData.h"
#include "Shell.h"
#include "ProductBuilder.h"
#include "ClientBuilder.h"
#include "stdafx.h"

class System
{
private:
	static shared_ptr<ProductData> products;
	static shared_ptr<ClientData> clients;
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

	static shared_ptr<ProductData> GetProducts();
	static shared_ptr<ClientData> GetClients();
};

