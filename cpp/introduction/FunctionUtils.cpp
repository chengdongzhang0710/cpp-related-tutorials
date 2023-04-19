#include "FunctionUtils.h"

void swap(int num1, int num2)
{
	cout << "Before: " << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	int temp = num1;
	num1 = num2;
	num2 = temp;

	cout << "After: " << endl;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;

	return;  // 返回值不需要的时候，可以不写return
}
