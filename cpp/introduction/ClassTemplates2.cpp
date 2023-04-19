#include <iostream>
using namespace std;

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 is showing" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 is showing" << endl;
	}
};

template <typename T>
class MyClass
{
public:
	T obj;

	void func1()
	{
		obj.showPerson1();
	}

	void func2()
	{
		obj.showPerson2();
	}
};

void test1()
{
	MyClass<Person1> m;
	m.func1();
	// m.func2();  // 错误！
}

int main()
{
	test1();

	system("pause");
	return 0;
}
