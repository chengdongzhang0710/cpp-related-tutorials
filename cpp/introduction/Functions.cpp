#include <iostream>
#include "FunctionUtils.h"
using namespace std;

int max(int a, int b);  // 提前告诉编译器函数的存在，可以利用函数的声明

int main()
{
	int a = 10;
	int b = 20;

	cout << "Max Value: " << max(a, b) << endl;

	swap(a, b);

	cout << "Global:" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	system("pause");
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
