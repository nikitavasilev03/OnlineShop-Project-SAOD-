#include "System.h"

void System::Start() {
	Shell shell;
	shell.Start();
}

void System::Add(shared_ptr<EntityBuilder> entityBuilder) {
	try
	{
		auto obj = entityBuilder->Create();
		Tables::AddToItem(obj);
	}
	catch (const std::exception & exp)
	{
		cout << exp.what() << endl;
	}
}

void System::Remove(shared_ptr<EntityBuilder> entityBuilder, int id) {
	try
	{
		auto obj = entityBuilder->CreateEmpty();
		obj->SetID(id);
		Tables::RemoveItem(obj);
	}
	catch (const std::exception & exp)
	{
		cout << exp.what() << endl;
	}
}
void System::Edit(shared_ptr<EntityBuilder> entityBuilder, int id) {
	try
	{
		auto obj = entityBuilder->Create();
		obj->SetID(id);
		Tables::EditItem(obj);
	}
	catch (const std::exception & exp)
	{
		cout << exp.what() << endl;
	}
}
void System::Print(shared_ptr<ListData> listData) {
	for (auto item : *listData->GetItems())
		cout << item->ToString() << endl;
}
void System::Print(shared_ptr<ListData> listData, int id) {

}
void System::SaveData() {

	string msg = "";

	fstream fs;
	fs.open("tableProducts.table", fstream::out);
	if (fs.is_open()) {
		for (auto item : *Tables::products->GetItems())
		{
			Product* pd = (Product*)&(*item);
			msg = to_string(pd->GetID()) + "|" +
				pd->GetName() + "|" +
				to_string(pd->GetPrice()) + "|" +
				to_string(pd->GetUOM());

			fs << msg << endl;
		}
		fs.close();
	}
	else
	{
		cout << "SAVE DATA PRODUCTS ERRORR!" << endl;
	}

	fs.open("tableClients.table", fstream::out);
	if (fs.is_open()) {
		for (auto item : *Tables::clients->GetItems())
		{
			Client* pd = (Client*)&(*item);
			msg = to_string(pd->GetID()) + "|" +
				pd->GetSecondName() + "|" +
				pd->GetFirstName() + "|" +
				pd->GetLastName() + "|" +
				pd->GetEmail() + "|" +
				pd->GetAddress() + "|" +
				pd->GetPhone() + "|" +
				to_string(pd->IsRegularClient()) + "|" +
				to_string(pd->GetTotalMoney());

			fs << msg << endl;
		}
		fs.close();
	}
	else {
		cout << "SAVE DATA CLIENTS ERRORR!" << endl;
	}

	fs.open("Tablesales.table", fstream::out);
	if (fs.is_open()) {
		for (auto item : *Tables::sales->GetItems())
		{
			Sale* pd = (Sale*)&(*item);
			msg = to_string(pd->GetID()) + "|" +
				to_string(pd->GetProductID()) + "|" +
				to_string(pd->GetClientID()) + "|" +
				DateToString(pd->GetDateSale()) + "|" +
				DateToString(pd->GetDateDelivery()) + "|" +
				to_string(pd->GetCount()) + "|" +
				to_string(pd->GetTotalPrice());
			fs << msg << endl;
		}
		fs.close();
	}
	else {
		cout << "SAVE DATA SALES ERRORR!" << endl;
	}
}

void System::LoadData() {
	string msg = "";

	fstream fs;
	fs.open("tableProducts.table", fstream::in);
	while (fs.is_open() && !fs.eof())
	{
		msg = input(fs);
		if (msg == "")
			continue;
		auto strs = Split(msg, "|");
		if (strs.size() != 4) {
			cout << "Load Error" << endl;
			continue;
		}

		int id, price, iuom;
		string name;

		istringstream sid(strs[0]);
		name = strs[1];
		istringstream sprice(strs[2]);
		istringstream sioum(strs[3]);

		sid >> id;
		sprice >> price;
		sioum >> iuom;

		if (sid.fail() || sprice.fail() || sioum.fail()) {
			cout << "Load Error" << endl;
			continue;
		}
		Tables::products->Add((shared_ptr<Entity>)(new Product(id, name, price, (MeasurementType)iuom)));
	}
	if (!fs.is_open()) {
		cout << "Load Error" << endl;
	}
	fs.close();

	fs.open("tableClients.table", fstream::in);
	while (fs.is_open() && !fs.eof())
	{
		msg = input(fs);
		if (msg == "")
			continue;
		auto strs = Split(msg, "|");
		if (strs.size() != 9) {
			cout << "Load Error" << endl;
			continue;
		}

		int id, total_pay;
		bool isRegularClient;

		istringstream sid(strs[0]);
		string second_name = strs[1];
		string first_name = strs[2];
		string last_name = strs[3];
		string email = strs[4];
		string address = strs[5];
		string phone = strs[6];
		istringstream sisRegularClient(strs[7]);
		istringstream sisTotalMoney(strs[8]);

		sisRegularClient >> isRegularClient;
		sid >> id;
		sisTotalMoney >> total_pay;

		if (sid.fail() || sisRegularClient.fail() || sisTotalMoney.fail()) {
			cout << "Load Error" << endl;
			continue;
		}

		auto entity = (shared_ptr<Entity>)(new Client(id, second_name, first_name, email, last_name, address, phone));
		auto client = (Client*)entity->GetEntity();
		client->SetRegularClient(isRegularClient);
		client->SetTotalPay(total_pay);
		Tables::clients->Add(entity);
	}
	if (!fs.is_open()) {
		cout << "Load Error" << endl;
	}
	fs.close();

	fs.open("Tablesales.table", fstream::in);
	while (fs.is_open() && !fs.eof())
	{
		msg = input(fs);
		if (msg == "")
			continue;
		auto strs = Split(msg, "|");
		if (strs.size() != 7) {
			cout << "Load Error" << endl;
			continue;
		}

		int id, product_id, client_id, pcount, total_price;
		//string 
		istringstream s_id(strs[0]);
		istringstream s_product_id(strs[1]);
		istringstream s_client_id(strs[2]);
		Date date_sale = DateFromString(strs[3]);
		Date date_delivery = DateFromString(strs[4]);
		istringstream s_pcount(strs[5]);
		istringstream s_total_price(strs[6]);

		s_id >> id;
		s_product_id >> product_id;
		s_client_id >> client_id;
		s_pcount >> pcount;
		s_total_price >> total_price;

		if (s_id.fail() || s_product_id.fail() || s_client_id.fail() || s_pcount.fail() || s_total_price.fail() || date_sale.year == -1 || date_delivery.year == -1) {
			cout << "Load Error" << endl;
			continue;
		}

		auto entity = (shared_ptr<Sale>)(new Sale(id, product_id, client_id, date_sale, date_delivery, pcount));
		auto sale = ((Sale*)&(*entity));
		sale->SetTotalPrice(total_price);
		Tables::sales->Add(entity);
	}
	if (!fs.is_open()) {
		cout << "Load Error" << endl;
	}
	fs.close();

	cout << "LOADING IS COMPLITE" << endl;
}

shared_ptr<ProductsData> System::GetProducts() {
	return Tables::products;
}
shared_ptr<ClientsData> System::GetClients() {
	return Tables::clients;
}
shared_ptr<SalesData>  System::GetSales() {
	return Tables::sales;
}