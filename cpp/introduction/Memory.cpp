#include <iostream>
using namespace std;

// 全局变量
int ga = 10;
int gb = 10;

const int cga = 10;
const int cgb = 10;

int* func1()
{
	int a = 10;  // 局部变量，存放在栈区，栈区的数据在函数执行完后自动释放
	return &a;
}

int* func2()
{
	// 指针本质也是局部变量放在栈上，指针保存的数据是放在堆区
	int* p = new int(10);
	return p;
}

void test1()
{
	int* p = func2();
	cout << *p << endl;
	delete p;
	// cout << *p << endl;  // 错误，内存已经被释放，再次访问就是非法操作，会报错
}

void test2()
{
	int* arr = new int[10];

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	delete[] arr;  // 释放数组的时候要加[]才可以
}

int main()
{
	// 普通局部变量
	int a = 10;
	int b = 10;

	// 静态变量
	static int sa = 10;
	static int sb = 10;

	// 常量
	// 字符串常量

	// const修饰的变量
	// const修饰的全局变量：全局常量
	// const修饰的局部变量：局部常量
	const int cla = 10;
	const int clb = 10;

	cout << "The address of local variable a is " << (int)&a << endl;
	cout << "The address of local variable b is " << (int)&b << endl;

	cout << "The address of global variable ga is " << (int)&ga << endl;
	cout << "The address of global variable gb is " << (int)&gb << endl;

	cout << "The address of static variable sa is " << (int)&sa << endl;
	cout << "The address of static variable sb is " << (int)&sb << endl;

	cout << "The address of string const variable is " << (int)&"Hello World" << endl;

	cout << "The address of const global variable cga is " << (int)&cga << endl;
	cout << "The address of const global variable cgb is " << (int)&cgb << endl;

	cout << "The address of const local variable cga is " << (int)&cla << endl;
	cout << "The address of const local variable cgb is " << (int)&clb << endl;

	// 栈区
	int* p1 = func1();
	cout << *p1 << endl;  // 第一次可以打印正确的数字是因为编译器做了保留
	cout << *p1 << endl;  // 第二次这个数据就不再保留了

	// 堆区
	int* p2 = func2();
	cout << *p2 << endl;
	cout << *p2 << endl;

	// new操作符
	test1();
	test2();

	system("pause");
	return 0;
}
