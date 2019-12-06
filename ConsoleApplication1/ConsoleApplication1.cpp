#include "stdafx.h"
#include "MyClass.h"
#include <list>
#include <memory>

int MyClass::N = 0;

#define _SHARED_PTR

#ifdef  _SHARED_PTR
list<MyClass*> myList;
void Init() {
	myList.push_back(new MyClass);
}
void Clean() {
	try {
		for (auto& p : myList)
			delete p;
	}
	catch (...)
	{
		cout << "Error" << endl;
	}
}
MyClass* GetObject1() {
	return new MyClass();
}
MyClass* GetObject2() {
	auto f = myList.begin();
	if (f != myList.end())
		return *f;
	else
		return 0;
}
#else
list<shared_ptr<MyClass>> myList;
void Init() {
	myList.push_back(shared_ptr<MyClass>(new MyClass));
}
void Clean() {

}
shared_ptr<MyClass> GetObject1(){
	return shared_ptr<MyClass>(new MyClass);
}
shared_ptr<MyClass> GetObject2() {
	auto f = myList.begin();
	if (f != myList.end())
		return *f;
	else
		return 0;
}
#endif // ! _SHARED_PTR


int main()
{
	Init();

	auto p1 = GetObject1();
	auto p2 = GetObject2();

	if (p1)
	{
		p1->Method1();
	}
	if (p2)
		p2->Method1();

#ifdef _SHARED_PTR
	delete p1; 
	delete p2;
#endif // !_SHARED_PTR
	Clean();
	cout << "The End" << endl;
	return 0;
}
