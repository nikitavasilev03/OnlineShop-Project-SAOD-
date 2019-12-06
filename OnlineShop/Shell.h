#pragma once

#include "stdafx.h"
#include "System.h"

class Shell
{
private:
	
public:
	static vector<string> Split(string in_str, const char* delimiter);

	Shell();
	void Start();
};

