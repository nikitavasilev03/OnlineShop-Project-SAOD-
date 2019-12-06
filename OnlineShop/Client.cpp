#include "Client.h"

Client::Client(string _second_name, string _first_name, string _email, string _last_name, string _address, string _phone) : Entity() {
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
}

Client::Client(int id, string _second_name, string _first_name, string _email, string _last_name, string _address, string _phone) : Entity(id) {
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

string Client::ToString() {
	return to_string(GetID()) + " " + second_name + " " + first_name + " " + last_name + " " + email + " " + phone + " " + address + " " + to_string(isRegularClient);
}
