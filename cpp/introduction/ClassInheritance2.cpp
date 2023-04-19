#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base constructor is called" << endl;
	}

	~Base()
	{
		cout << "Base destructor is called" << endl;
	}
};

class Son : public Base
{
public:
	Son()
	{
		cout << "Son constructor is called" << endl;
	}

	~Son()
	{
		cout << "Son destructor is called" << endl;
	}
};

void test1()
{
	Son s;
}

int main()
{
	test1();
	
	system("pause");
	return 0;
}
