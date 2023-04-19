#include <iostream>
using namespace std;

void myPrint(int a, int b)
{
	cout << "Normal function is called" << endl;
}

template <typename T>
void myPrint(T a, T b)
{
	cout << "Function template is called" << endl;
}

template <typename T>
void myPrint(T a, T b, T c)
{
	cout << "Function template with reload is called" << endl;
}

void test1()
{
	int a = 10, b = 20;

	// 如果函数模板和普通函数都可以调用，优先调用普通函数
	myPrint(a, b);

	// 通过空模板参数列表强制调用函数模板
	myPrint<>(a, b);

	// 函数模板也可以发生重载
	myPrint(a, b, 10);

	// 如果函数模板可以产生更好的匹配，优先调用函数模板
	char c1 = 'a', c2 = 'b';
	myPrint(c1, c2);
}

int main()
{
	test1();

	system("pause");
	return 0;
}
