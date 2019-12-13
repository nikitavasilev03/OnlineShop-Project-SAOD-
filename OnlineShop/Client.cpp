#include "Client.h"

Client::Client() {
	Init("", "", "", "", "", "");
}

Client::Client(string _second_name, string _first_name, string _email, string _last_name, string _address, string _phone) : Entity() {
	Init(_second_name, _first_name, _email, _last_name, _address, _phone);
}

Client::Client(int id, string _second_name, string _first_name, string _email, string _last_name, string _address, string _phone) : Entity(id) {
	Init(_second_name, _first_name, _email, _last_name, _address, _phone);
}

void Client::Init(string _second_name, string _first_name, string _email, string _last_name, string _address, string _phone) {
	if (_second_name == "")
		second_name = "none";
	else
		second_name = _second_name;

	if (_first_name == "")
		first_name = "none";
	else
		first_name = _first_name;

	if (_last_name == "")
		last_name = "none";
	else
		last_name = _last_name;

	if (_email == "")
		email = "none";
	else
		email = _email;

	if (_address == "")
		address = "none";
	else
		address = _address;

	if (_phone == "")
		phone = "none";
	else
		phone = _phone;

	isRegularClient = false;
	total_pay = 0;
}

string Client::GetSecondName() {
	return second_name;
}
string Client::GetFirstName() {
	return first_name;
}
string Client::GetLastName() {
	return last_name;
}
string Client::GetAddress() {
	return address;
}
string Client::GetEmail() {
	return email;
}
string Client::GetPhone() {
	return phone;
}
bool Client::IsRegularClient() {
	return isRegularClient;
}
int Client::GetTotalMoney() {
	return total_pay;
}

void Client::SetRegularClient(bool f) {
	isRegularClient = f;
}
void Client::SetTotalPay(int money) {
	total_pay = money;
}
void Client::IncTotalPay(int money) {
	total_pay += money;
}

void Client::SetSecondName(string name) {
	this->second_name = name;
}
void Client::SetFirstName(string name) {
	this->first_name = name;
}
void Client::SetLastName(string name) {
	this->last_name = name;
}
void Client::SetAddress(string address) {
	this->address = address;
}
void Client::SetEmail(string email) {
	this->email = email;
}
void Client::SetPhone(string phone) {
	this->phone = phone;
}

string Client::ToString() {
	return
		"ID: " + to_string(GetID()) + ",  " +
		"Second name: " + second_name + ",  " +
		"Firs name: " + first_name + ",  " +
		"Last name: " + last_name + ",  " +
		"Email: " + email + ",  " +
		"Phone: " + phone + ",  " +
		"Address: " + address + ",  " +
		"Is regular client: " + to_string(isRegularClient) + ",  " +
		"Total pay: " + to_string(total_pay);
}