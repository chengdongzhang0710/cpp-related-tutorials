#include <iostream>
using namespace std;

int main()
{
	int a1 = 10;
	int b1 = ++a1 * 10;
	cout << "a1 = " << a1 << endl;
	cout << "b1 = " << b1 << endl;  // 输出110

	int a2 = 10;
	int b2 = a2++ * 10;
	cout << "a2 = " << a2 << endl;
	cout << "b2 = " << b2 << endl;  // 输出100

	int a = 10;
	cout << "!a = " << !a << endl;  // 输出0
	cout << "!!a = " << !!a << endl;  // 输出1

	system("pause");
	return 0;
}
