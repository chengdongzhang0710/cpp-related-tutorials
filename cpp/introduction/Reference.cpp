#include <iostream>
using namespace std;

void swap(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int& func1()
{
	int a = 10;
	return a;
}

int& func2()
{
	static int a = 10;  // 静态变量存放在全局区，全局区上的数据在程序结束后系统释放
	return a;
}

// 发现是引用，转换为int* const ref = &a
void func(int& ref)
{
	ref = 100;  // ref是引用，转换为*ref = 100
}

void showValue(const int& v)
{
	// v = 1000;  // 错误
	cout << "v = " << v << endl;
}

int main()
{
	/*
	int a = 10;
	int& b = a;
	b = 20;
	cout << "a = " << a << endl;  // 输出20

	// int& c;  // 错误，引用必须初始化
	int c = 100;
	b = c;  // 赋值操作而不是更改引用
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	int num1 = 10;
	int num2 = 20;

	swap(num1, num2);  // 引用传递，形参会修饰实参

	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	int& ref = func1();
	cout << "ref = " << ref << endl;  // 第一次结果正确是因为编译器做了保留
	cout << "ref = " << ref << endl;  // 第二次结果错误是因为a的内存已经释放

	int& ref2 = func2();
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	func2() = 1000;  // 如果函数的返回值是引用，这个函数调用可以作为左值
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	int a = 10;

	// 自动转换为int* const ref = &a
	// 指针常量是指针指向不可改，也说明为什么引用不可改
	int& ref = a;
	ref = 20;  // 内部发现ref是引用，自动转换为*ref = 20

	func(a);
	*/

	int a = 10;
	// int& ref = 10;  // 错误，引用必须引一块合法的内存空间
	const int& ref = 10;  // 加上const后编译器将代码修改为：int temp = 10; const int& ref = temp;
	// ref = 20;  // 加入const之后变为只读不可以修改

	int b = 100;
	showValue(b);
	cout << "b = " << b << endl;

	system("pause");
	return 0;
}
