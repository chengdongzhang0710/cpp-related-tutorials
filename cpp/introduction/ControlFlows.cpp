#include <iostream>
using namespace std;

int main()
{
	// 三目运算符
	int a = 10;
	int b = 20;
	int c = 0;

	c = a > b ? a : b;
	cout << "c = " << c << endl;  // 输出20

	(a < b ? a : b) = 100;
	cout << "a = " << a << endl;  // 输出100
	cout << "b = " << b << endl;  // 输出20

	// switch语句的用法
	cout << "Score the movie: ";

	int score = 0;
	cin >> score;

	switch (score)
	{
	case 5:
		cout << "Excellent" << endl;
		break;
	case 4:
		cout << "Good" << endl;
		break;
	case 3:
		cout << "Normal" << endl;
		break;
	default:
		cout << "Bad" << endl;
		break;
	}

	// do-while语句的用法
	int num = 0;
	do
	{
		cout << num << endl;
		num++;
	}
	while (num < 10);

	// for语句的用法
	int i = 0;
	for (;;)
	{
		if (i >= 10)
		{
			break;
		}
		cout << i << endl;
		i++;
	}

	// goto语句的用法
	cout << "The FIRST line" << endl;
	cout << "The SECOND line" << endl;
	goto FLAG;
	cout << "The THIRD line" << endl;
	cout << "The FORTH line" << endl;
FLAG:
	cout << "The FIFTH line" << endl;

	system("pause");
	return 0;
}
