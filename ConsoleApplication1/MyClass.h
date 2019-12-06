#pragma once

#include "stdafx.h"

class MyClass
{
public:
	static int N;
	MyClass() {
		cout << "--constructor " << ++N << endl;
	}
	~MyClass() {
		cout << "--destructor " << --N << endl;
	}
	void Method1() {
		cout << "--->Method1" << endl;
	}
};

