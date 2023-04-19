#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
class Person;

template <typename T1, typename T2>
void printPerson2(Person<T1, T2> p)
{
	cout << "Name: " << p.personName << " Age: " << p.personAge << endl;
}

template <typename T1, typename T2>
class Person
{
private:
	T1 personName;
	T2 personAge;

public:
	Person(T1 name, T2 age)
	{
		this->personName = name;
		this->personAge = age;
	}

	// 全局函数类内实现
	friend void printPerson(Person<T1, T2> p)
	{
		cout << "Name: " << p.personName << " Age: " << p.personAge << endl;
	}

	// 全局函数类外实现
	// 1. 加空参数列表
	// 2. 需要提前让编译器知道全局函数的存在
	friend void printPerson2<>(Person<T1, T2> p);
};

void test1()
{
	Person<string, int> p("Tom", 20);
	printPerson(p);
	printPerson2(p);
}

int main()
{
	test1();
	
	system("pause");
	return 0;
}
