#include <iostream>
using namespace std;

class Base
{
public:
	// 纯虚函数
	// 只要有一个纯虚函数，这个类称为抽象类
	virtual void func() = 0;
};

class Son : public Base
{
public:
	virtual void func()
	{
		cout << "func is called" << endl;
	}
};

void test1()
{
	//Base b;  // 错误！抽象类无法实例化对象
	//new Base;  // 错误！抽象类无法实例化对象

	//Son s;  // 子类必须重写父类中的纯虚函数，否则无法实例化对象

	Base* base = new Son;
	base->func();
	delete base;
}

int main()
{
	test1();
	
	system("pause");
	return 0;
}
