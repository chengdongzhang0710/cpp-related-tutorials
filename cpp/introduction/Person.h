#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
class Person
{
public:
	T1 personName;
	T2 personAge;

	Person(T1 name, T2 age);
	void show();
};
