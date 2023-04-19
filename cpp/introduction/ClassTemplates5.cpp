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

template <typename T1, typename T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->personName = name;
	this->personAge = age;
}

template <typename T1, typename T2>
void Person<T1, T2>::show()
{
	cout << "Name: " << this->personName << " Age: " << this->personAge << endl;
}

void test1()
{
	Person<string, int> p("Tom", 10);
	p.show();
}

int main()
{
	test1();
	
	system("pause");
	return 0;
}
