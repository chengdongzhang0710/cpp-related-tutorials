#include <iostream>
#include <string>
using namespace std;

class AbstractCalculator
{
public:
	int num1;
	int num2;

	virtual int getResult()
	{
		return 0;
	}
};

class AddCalculator : public AbstractCalculator
{
public:
	int getResult()
	{
		return num1 + num2;
	}
};

class SubCalculator : public AbstractCalculator
{
public:
	int getResult()
	{
		return num1 - num2;
	}
};

class MultiCalculator : public AbstractCalculator
{
public:
	int getResult()
	{
		return num1 * num2;
	}
};

void test1()
{
	AbstractCalculator* abs = new AddCalculator;
	abs->num1 = 10;
	abs->num2 = 10;

	cout << abs->num1 << " + " << abs->num2 << " = " << abs->getResult() << endl;

	delete abs;

	abs = new SubCalculator;
	abs->num1 = 10;
	abs->num2 = 10;

	cout << abs->num1 << " - " << abs->num2 << " = " << abs->getResult() << endl;

	delete abs;

	abs = new MultiCalculator;
	abs->num1 = 10;
	abs->num2 = 10;

	cout << abs->num1 << " * " << abs->num2 << " = " << abs->getResult() << endl;

	delete abs;
}

int main()
{
	test1();
	
	system("pause");
	return 0;
}
