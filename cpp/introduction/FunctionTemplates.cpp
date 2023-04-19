#include <iostream>
using namespace std;

// 函数模板
template <typename T> // 声明一个模板，告诉编译器后面代码中紧跟的T不要报错，T是一个通用数据类型
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
void func()
{
	cout << "func is called" << endl;
}

void test1()
{
	int a = 10, b = 20;

	// 使用两种方式使用函数模板
	// 1. 自动类型推导
	mySwap(a, b);
	// 2. 显示指定类型
	mySwap<int>(a, b);

	cout << "a = " << a << ", b = " << b << endl;
}

void test2()
{
	int a = 10, b = 20;
	char c = 'c';

	// mySwap(a, c);  // 错误！推导不出一致的T类型

	cout << "a = " << a << ", b = " << b << endl;
}

void test3()
{
	// func();  // 错误！没有确定T的数据类型
	func<int>();
}

int main()
{
	// test1();

	// test2();
	test3();

	system("pause");
	return 0;
}
