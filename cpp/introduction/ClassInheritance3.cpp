#include <iostream>
using namespace std;

class Base
{
public:
	int var;

	Base()
	{
		var = 100;
	}

	void func()
	{
		cout << "func in Base is called" << endl;
	}

	void func(int)
	{
		cout << "func(int) in Son is called" << endl;
	}
};

class Son : public Base
{
public:
	int var;

	Son()
	{
		var = 200;
	}

	void func()
	{
		cout << "func in Son is called" << endl;
	}
};

// 同名成员属性
void test1()
{
	Son s;
	cout << "Son var = " << s.var << endl;
	cout << "Base var = " << s.Base::var << endl;
}

// 同名成员函数
void test2()
{
	Son s;
	s.func();
	s.Base::func();

	//s.func(100);  // 错误！如果子类中出现和父类同名的成员函数，子类的同名函数会隐藏父类所有的同名函数
	s.Base::func(100);
}

int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}
