#include "System.h"

shared_ptr<ProductData> System::products = NULL;
shared_ptr<ClientData> System::clients = NULL;
shared_ptr<SaleData> System::sales = NULL;

void System::Start() {

	products = (shared_ptr<ProductData>)(new ProductData());
	clients = (shared_ptr<ClientData>)(new ClientData());
	sales = (shared_ptr<SaleData>)(new SaleData());

	Shell shell;
	shell.Start();

}

void System::Add(shared_ptr<ListData> listData, shared_ptr<EntityBuilder> entityBuilder) {
	auto obj = entityBuilder->Create();
	if (obj) {
		try
		{
			listData->Add(obj);
		}
		catch (const std::exception & exp)
		{
			cout << exp.what() << endl;
		}
	}
	else {
		cout << "The object is missing" << endl;
	}
}
void System::Remove(shared_ptr<ListData> listData, int id) {

}
void System::Edit(shared_ptr<ListData> listData, int id) {

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
		for (auto item : *products->GetItems())
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
		for (auto item : *clients->GetItems())
		{
			Client* pd = (Client*)&(*item);
			msg = to_string(pd->GetID()) + "|" +
				pd->GetSecondName() + "|" +
				pd->GetFirstName() + "|" +
				pd->GetLastName() + "|" +
				pd->GetEmail() + "|" +
				pd->GetAddress() + "|" +
				pd->GetPhone() + "|" +
				to_string(pd->IsRegularClient());

			fs << msg << endl;
		}
		fs.close();
	}
	else {
		cout << "SAVE DATA CLIENTS ERRORR!" << endl;
	}

	fs.open("tableSales.table", fstream::out);
	if (fs.is_open()) {
		for (auto item : *sales->GetItems())
		{
			Sale* pd = (Sale*)&(*item);
			msg = to_string(pd->GetID()) + "|" +
				to_string(pd->GetProductID()) + "|" +
				to_string(pd->GetClientID()) + "|" +
				System::DateToString(pd->GetDateSale()) + "|" +
				System::DateToString(pd->GetDateDelivery()) + "|" +
				to_string(pd->GetCount()) + "|" +
				to_string(pd->GetSummatyPay());
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
		getline(fs, msg);
		if (msg == "")
			continue;
		auto strs = Shell::Split(msg, "|");
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
		products->Add((shared_ptr<Entity>)(new Product(id, name, price, (MeasurementType)iuom)));
	}
	if (!fs.is_open()) {
		cout << "Load Error" << endl;
	}
	fs.close();

	fs.open("tableClients.table", fstream::in);
	while (fs.is_open() && !fs.eof())
	{
		getline(fs, msg);
		if (msg == "")
			continue;
		auto strs = Shell::Split(msg, "|");
		if (strs.size() != 8) {
			cout << "Load Error" << endl;
			continue;
		}

		int id;
		bool isRegularClient;

		istringstream sid(strs[0]);
		string second_name = strs[1];
		string first_name = strs[2];
		string last_name = strs[3];
		string email = strs[4];
		string address = strs[5];
		string phone = strs[6];
		istringstream sisRegularClient(strs[7]);

		sisRegularClient >> isRegularClient;
		sid >> id;

		if (sid.fail() || sisRegularClient.fail()) {
			cout << "Load Error" << endl;
			continue;
		}

		auto entity = (shared_ptr<Entity>)(new Client(id, second_name, first_name, email, last_name, address, phone));
		auto client = (Client*)&(*entity);
		client->SetRegularClient(isRegularClient);
		clients->Add(entity);
	}
	if (!fs.is_open()) {
		cout << "Load Error" << endl;
	}
	fs.close();

	fs.open("tableSales.table", fstream::in);
	while (fs.is_open() && !fs.eof())
	{
		getline(fs, msg);
		if (msg == "")
			continue;
		auto strs = Shell::Split(msg, "|");
		if (strs.size() != 7) {
			cout << "Load Error" << endl;
			continue;
		}

		int id, product_id, client_id, pcount, summary_pay;
		//string 
		istringstream s_id(strs[0]);
		istringstream s_product_id(strs[1]);
		istringstream s_client_id(strs[2]);
		Date date_sale = System::DateFromString(strs[3]);
		Date date_delivery = System::DateFromString(strs[4]);
		istringstream s_pcount(strs[5]);
		istringstream s_summary_pay(strs[6]);

		s_id >> id;
		s_product_id >> product_id;
		s_client_id >> client_id;
		s_pcount >> pcount;
		s_summary_pay >> summary_pay;

		if (s_id.fail() || s_product_id.fail() || s_client_id.fail() || s_pcount.fail() || s_summary_pay.fail || date_sale.year == -1 || date_delivery.year == -1) {
			cout << "Load Error" << endl;
			continue;
		}

		auto entity = (shared_ptr<Sale>)(new Sale(id, product_id, client_id, date_sale, date_delivery, pcount));
		auto sale = ((Sale*)&(*entity));
		sale->SetSummaryPay(summary_pay);
		sales->Add(entity);
	}
	if (!fs.is_open()) {
		cout << "Load Error" << endl;
	}
	fs.close();

	cout << "LOADING IS COMPLITE" << endl;
}

shared_ptr<ProductData> System::GetProducts() {
	return products;
}
shared_ptr<ClientData> System::GetClients() {
	return clients;
}
shared_ptr<SaleData>  System::GetSales() {
	return sales;
}

Date System::DateFromString(string in_str) {
	auto strs = Shell::Split(in_str, ".");
	if (strs.size() != 3)
		return Date(0, 0, -1);
	int day, mounth, year;
	istringstream sday(strs[0]);
	istringstream smounth(strs[1]);
	istringstream syear(strs[2]);

	sday >> day;
	smounth >> mounth;
	syear >> year;

	return Date(day, mounth, year);
}

string System::DateToString(Date in_date) {
	return to_string(in_date.day) + "." + to_string(in_date.mounth) + "." + to_string(in_date.year);
}