#include <iostream>
using namespace std;

class MyInteger
{
	friend ostream& operator<<(ostream& out, MyInteger myInt);

private:
	int myNum;

public:
	MyInteger()
	{
		myNum = 0;
	}

	// 前置递增
	MyInteger& operator++()
	{
		myNum++;
		return *this;
	}

	// 后置递增
	// int代表占位参数，可以用于区分前置和后置递增
	MyInteger operator++(int)
	{
		MyInteger temp = *this;
		myNum++;
		return temp;
	}
};

ostream& operator<<(ostream& out, MyInteger myInt)
{
	out << myInt.myNum;
	return out;
}

void test1()
{
	MyInteger myInt;
	cout << ++(++myInt) << endl;
	cout << myInt << endl;
}

void test2()
{
	MyInteger myInt;

	cout << myInt++ << endl;
	cout << myInt << endl;
}

int main()
{
	test1();
	test2();

	system("pause");
	return 0;
}
