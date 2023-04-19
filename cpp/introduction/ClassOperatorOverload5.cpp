#include <iostream>
#include <string>
using namespace std;

class MyPrint
{
public:
	void operator()(string str)
	{
		cout << str << endl;
	}
};

class MyAdd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};

void test1()
{
	MyPrint myPrint;
	myPrint("Hello World");  // 仿函数
}

void test2()
{
	MyAdd myAdd;
	int res = myAdd(100, 100);
	cout << "res = " << res << endl;

	// 匿名函数对象
	cout << "MyAdd()(100, 100) = " << MyAdd()(100, 100) << endl;
}

int main()
{
	//test1();
	test2();
	
	system("pause");
	return 0;
}
