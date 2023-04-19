#include <iostream>
using namespace std;

template <typename T>
class Base
{
public:
	T var;
};

// 必须要知道父类中的T类型，才能继承给子类
class Son : public Base<int>
{
};

template <typename T1, typename T2>
class Son2 : public Base<T2>
{
public:
	T1 obj;

	Son2()
	{
		cout << "The type of T1 is " << typeid(T1).name() << endl;
		cout << "The type of T2 is " << typeid(T2).name() << endl;
	}
};

void test1()
{
	Son s1;
	Son2<int, char> s2;
}

int main()
{
	test1();

	system("pause");
	return 0;
}
