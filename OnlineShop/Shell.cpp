#include "Shell.h"

Shell::Shell() {

}

void Shell::Start() {
	string input;

	cout << "Добро пожаловать в систему комерческого отдела компании" << endl;
	cout << "Загрузить базу данных? (y/n)" << endl;
	cout << "-> ";
	getline(cin, input);
	if (input == "y") {
		System::LoadData();
	}

	while (true)
	{
		cout << "-> ";
		getline(cin, input);
		if (input == "")
			continue;
		vector<string> strs = Split(input, " ");
		//cout << strs.size() << endl;
		//Тип данных

		if (strs.size() == 1) {
			if (strs[0] == "clear") {
				system("CLS");
			}
			if (strs[0] == "exit") {
				
				cout << "Сохранить базу данных? (y/n)" << endl;
				cout << "-> ";
				getline(cin, input);
				if (input == "y") {
					System::SaveData();
				}

				cout << "Goodbye :)" << endl;
				break;
			}
			else
			{
				cout << "Некоректный ввод" << endl;
			}
		}

		else if (strs.size() == 2) {
			shared_ptr<ListData> listData = NULL;
			shared_ptr<EntityBuilder> eb = NULL;
			if (strs[1] == "product" || strs[1] == "products") {
				listData = System::GetProducts();
				eb = (shared_ptr<EntityBuilder>)(new ProductBuilder());
			}
			else if (strs[1] == "client" || strs[1] == "clients") {
				listData = System::GetClients();
				eb = (shared_ptr<EntityBuilder>)(new ClientBuilder());
			}
			else if (strs[1] == "sale" || strs[1] == "sales") {
				listData = System::GetSales();
				eb = (shared_ptr<EntityBuilder>)(new SaleBuilder());
			}

			//Тип операции
			if (strs[0] == "add" && listData) {
				System::Add(listData, eb);
			}
			else if (strs[0] == "print" && listData) {
				System::Print(listData);
			}
			else {
				cout << "Некоректный ввод" << endl;
			}	
		}

		else
		{
			cout << "Некоректный ввод" << endl;
		}
	}
}

vector<string> Shell::Split(string in_str, const char* delimiter) {
	vector<string> str_arr;
	char* next_token = NULL;
	char* current_token = strtok_s(&in_str[0], delimiter, &next_token);
	while (current_token)
	{
		str_arr.push_back(current_token);
		current_token = strtok_s(NULL, delimiter, &next_token);
	}
	return str_arr;
}

