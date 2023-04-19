#include <iostream>
using namespace std;

class Base
{
public:
	static int var;

	static void func()
	{
		cout << "Static function func() in class Base is called" << endl;
	}

	static void func(int)
	{
		cout << "Static function func(int) in class Base is called" << endl;
	}
};

int Base::var = 100;

class Son : public Base
{
public:
	static int var;

	static void func()
	{
		cout << "Static function func() in class Son is called" << endl;
	}
};

int Son::var = 200;

// 同名静态成员属性
void test1()
{
	// 通过对象访问
	Son s;
	cout << "Son var = " << s.var << endl;
	cout << "Base var = " << s.Base::var << endl;

	// 通过类名访问
	cout << "Son var = " << Son::var << endl;
	cout << "Base var = " << Son::Base::var << endl;  // 第一个::代表通过类名的方式访问，第二个::代表访问父类作用域下
}

// 同名静态成员函数
void test2()
{
	// 通过对象访问
	Son s;
	s.func();
	s.Base::func();

	// 通过类名访问
	Son::func();
	Son::Base::func();

	//Son::func(100)  // 错误！
	Son::Base::func(100);
}

int main()
{
	//test1();
	test2();
	
	system("pause");
	return 0;
}
