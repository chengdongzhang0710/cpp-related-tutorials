#include <iostream>
using namespace std;

int myAdd1(int a, int b)
{
	return a + b;
}

template <typename T>
T myAdd2(T a, T b)
{
	return a + b;
}

void test1()
{
	int a = 10;
	char b = 'b';
	cout << myAdd1(a, b) << endl;
}

void test2()
{
	int a = 10;
	char b = 'b';
	// cout << myAdd2(a, b) << endl;  // 错误！不会发生隐式类型转换
	cout << myAdd2<int>(a, b) << endl;
}

int main()
{
	test1();
	test2();

	system("pause");
	return 0;
}
