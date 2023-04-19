#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
class Person
{
public:
	T1 personName;
	T2 personAge;

	Person(T1 name, T2 age) : personName(name), personAge(age)
	{
	}

	void show()
	{
		cout << "Name: " << this->personName << " Age: " << this->personAge << endl;
	}
};

// 指定传入的类型
void printPerson1(Person<string, int>& p)
{
	p.show();
}

// 参数模板化
template <typename T1, typename T2>
void printPerson2(Person<T1, T2>& p)
{
	p.show();
	cout << "The type of T1 is " << typeid(T1).name() << endl;
	cout << "The type of T2 is " << typeid(T2).name() << endl;
}

// 整个类模板化
template <typename T>
void printPerson3(T& p)
{
	p.show();
	cout << "The type of T is " << typeid(T).name() << endl;
}

void test1()
{
	Person<string, int> p("Tom", 10);
	printPerson1(p);
}

void test2()
{
	Person<string, int> p("Mike", 12);
	printPerson2(p);
}

void test3()
{
	Person<string, int> p("Ben", 14);
	printPerson3(p);
}

int main()
{
	test1();
	test2();
	test3();

	system("pause");
	return 0;
}
