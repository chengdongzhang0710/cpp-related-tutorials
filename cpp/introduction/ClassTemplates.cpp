#include <iostream>
#include <string>
using namespace std;

template <typename NameType, typename AgeType = int> // 类模板在模板参数列表中可以有默认参数，函数模板不可以
class Person
{
public:
	NameType personName;
	AgeType personAge;

	Person(NameType name, AgeType age) : personName(name), personAge(age)
	{
	}

	void show()
	{
		cout << "Name: " << this->personName << " Age: " << this->personAge << endl;
	}
};

void test1()
{
	Person<string, int> p1("Tom", 10);
	// Person p1("Tom", 10);  // 错误！类模板没有自动类型推导方式

	p1.show();
}

void test2()
{
	Person<string> p("Mike", 12);
	p.show();
}

int main()
{
	test1();
	test2();

	system("pause");
	return 0;
}
