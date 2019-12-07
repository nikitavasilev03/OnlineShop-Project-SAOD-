#pragma once
#include "Entity.h"
class Client :
	public Entity
{
private:
	string second_name;
	string first_name;
	string last_name;
	string address;
	string phone;
	string email;
	bool isRegularClient;

	int total_money;

	void Init(string _second_name, string _first_name, string _email, string _last_name, string _address, string _phone);
public:

	const int TOTAL_PAY_FOR_REGULAR_CLIENT = 5000;

	Client(int id, string _second_name, string _first_name, string _email, string _last_name = "", string _address = "", string _phone = "");
	Client(string _second_name, string _first_name, string _email, string _last_name = "", string _address = "", string _phone = "");
	
	void SetRegularClient(bool value = true) {
		isRegularClient = value;
	}

	string GetSecondName();
	string GetFirstName();
	string GetLastName();
	string GetAddress();
	string GetEmail();
	string GetPhone();
	bool IsRegularClient();
	int GetTotalMoney();

	void SetRegularClient(bool f = true);
	void SetTotalMoney(int money);
	void IncTotalMoney(int money);

	string ToString() override;
};

