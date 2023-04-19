#include <iostream>
using namespace std;

class Base1
{
public:
	int varA;

	Base1()
	{
		varA = 100;
	}
};

class Base2
{
public:
	int varA;

	Base2()
	{
		varA = 200;
	}
};

class Son : public Base1, public Base2
{
public:
	int varB;
	int varC;

	Son()
	{
		varB = 300;
		varC = 400;
	}
};


void test1()
{
	Son s;
	cout << "The size of class Son is " << sizeof(s) << endl;
	cout << "Base1 varA = " << s.Base1::varA << endl;
	cout << "Base2 varA = " << s.Base2::varA << endl;
}

int main()
{
	test1();
	
	system("pause");
	return 0;
}
