#include <iostream>
using namespace std;

// 函数默认参数
int func(int a, int b = 20, int c = 30)
{
	return a + b + c;
}

// 错误
//int func2(int a, int b = 20, int c)
//{
//	return a + b + c;
//}

//int func2(int a = 10, int b = 10);

// 函数占位参数
void func3(int a, int)
{
	cout << "This is func2" << endl;
}

void func4(int a, int = 10)
{
	cout << "This is func2" << endl;
}

// 函数重载
void func5()
{
	cout << "This is func5" << endl;
}

void func5(int a)
{
	cout << "This is func5(int a)" << endl;
}

void func5(double a)
{
	cout << "This is func5(double a)" << endl;
}

void func5(int a, double b)
{
	cout << "This is func5(int a, double b)" << endl;
}

void func5(double a, int b)
{
	cout << "This is func5(double a, int b)" << endl;
}

// 错误
//int func5(int a)
//{
//	cout << "This is func5(int a)" << endl;
//	return 0;
//}

// 引用作为重载条件
void func6(int& a)
{
	cout << "This is func6(int& a)" << endl;
}

void func6(const int& a)  // 类型不同
{
	cout << "This is func6(const int& a)" << endl;
}

// 函数重载碰到默认参数
void func7(int a)
{
	cout << "This is func7(int a)" << endl;
}

void func7(int a, int b = 10)
{
	cout << "This is func7(int a, int b)" << endl;
}

int main()
{
	cout << func(10, 30) << endl;

	func3(10, 10);
	func4(10);

	func5();
	func5(10);
	func5(3.14);
	func5(10, 3.14);
	func5(3.14, 10);

	int a = 10;
	func6(a);
	func6(10);

	//func7(10);  // 错误
	func7(10, 20);

	system("pause");
	return 0;
}

// 错误
//int func2(int a = 20, int b = 20)
//{
//	return a + b;
//}
