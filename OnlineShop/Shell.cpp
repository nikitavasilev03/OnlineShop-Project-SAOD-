#include "Shell.h"

Shell::Shell() {

}

void Shell::Start() {
	string str;

	cout << "Добро пожаловать в систему комерческого отдела компании" << endl;
	cout << "Загрузить базу данных? (y/n)" << endl;
	cout << "-> ";
	//getline(cin, input);
	str = input(cin);
	if (str == "y") {
		System::LoadData();
	}

	while (true)
	{
		cout << "-> ";
		str = input(cin);
		//getline(cin, input);
		if (str == "")
			continue;
		vector<string> strs = Split(str, " ");

		if (strs.size() == 1) {
			if (strs[0] == "clear") {
				system("CLS");
			}
			if (strs[0] == "help") {
				cout << "command help: выводит список доступных команд в среде" << endl;
				cout << "command clear: очищает консоль" << endl;
				cout << "command exit: выход" << endl;
				cout << "command add: добавить объект в таблицу, параметры (tablename)" << endl;
				cout << "command edit: изменить объект в таблице, параметры (tablename, id)" << endl;
				cout << "command remove: удалить объект из таблицы, параметры (tablename, id)" << endl;
				cout << "command print: вывести все объекты из таблицы, параметры (tablename)" << endl;
				cout << "command tables: выводит список доступных таблиц" << endl;
			}
			if (strs[0] == "tables") {
				cout << "products, clients, sales" << endl;
			}
			else if (strs[0] == "exit") {
				cout << "Сохранить базу данных? (y/n)" << endl;
				cout << "-> ";
				str = input(cin);
				if (str == "y") {
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
		else if (strs.size() >= 2) {
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
			if (strs.size() == 2) {
				if (strs[0] == "add" && eb) {
					System::Add(eb);
				}
				else if (strs[0] == "print" && listData) {
					System::Print(listData);
				}
				else {
					cout << "Некоректный ввод" << endl;
				}
			}
			else if (strs.size() == 3) {
				if (strs[0] == "edit" && eb) {
					int id;
					istringstream to_int(strs[2]);
					to_int >> id;
					if (to_int.fail()) {
						cout << "Некоректный ввод" << endl;
					}
					else {
						System::Edit(eb, id);
					}
				}
				if (strs[0] == "remove" && eb) {
					int id;
					istringstream to_int(strs[2]);
					to_int >> id;
					if (to_int.fail()) {
						cout << "Некоректный ввод" << endl;
					}
					else {
						System::Remove(eb, id);
					}
				}
			}
			else {
				cout << "Некоректный ввод" << endl;
			}
		}
		else {
			cout << "Некоректный ввод" << endl;
		}
	}
}