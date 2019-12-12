#include "Environment.h"

vector<string> Split(string in_str, const char* delimiter) {
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

Date DateFromString(string in_str) {
	auto strs = Split(in_str, ".");
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

string DateToString(Date in_date) {
	return to_string(in_date.day) + "." + to_string(in_date.month) + "." + to_string(in_date.year);
}

string input(istream& strm) {
	SetConsoleCP(1251);
	string str = "";
	getline(strm, str);
	SetConsoleCP(866);
	return str;
}