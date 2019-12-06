#include "System.h"

shared_ptr<ProductData> System::products = NULL;
shared_ptr<ClientData> System::clients = NULL;

void System::Start() {
	products = (shared_ptr<ProductData>)(new ProductData());
	clients = (shared_ptr<ClientData>)(new ClientData());
	Shell shell;
	shell.Start();
}

void System::Add(shared_ptr<ListData> listData, shared_ptr<EntityBuilder> entityBuilder) {
	auto obj = entityBuilder->Create();
	if (obj)
		listData->Add(obj);
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

	fs.open("tableClients.table", fstream::out);
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

	cout << "LOADING IS COMPLITE" << endl;
}

shared_ptr<ProductData> System::GetProducts() {
	return products;
}
shared_ptr<ClientData> System::GetClients() {
	return clients;
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