#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	string personName;
	int personAge;

	Person(string name, int age)
	{
		this->personName = name;
		this->personAge = age;
	}
};

template <typename T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <>
bool myCompare(Person& p1, Person& p2)
{
	if (p1.personName == p2.personName && p1.personAge == p2.personAge)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test1()
{
	int a = 10, b = 20;
	bool res = myCompare(a, b);
	if (res)
	{
		cout << "a == b" << endl;
	}
	else
	{
		cout << "a != b" << endl;
	}
}

void test2()
{
	Person p1("Tom", 10);
	Person p2("Tom", 12);
	bool res = myCompare(p1, p2);
	if (res)
	{
		cout << "p1 == p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl;
	}
}

int main()
{
	test1();
	test2();

	system("pause");
	return 0;
}
