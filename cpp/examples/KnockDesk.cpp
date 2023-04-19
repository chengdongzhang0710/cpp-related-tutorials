#include <iostream>
using namespace std;

/*
1. 先输出1到100这些数字
2. 从这100个数字中找到特殊数字，改为“敲桌子”
	7的倍数：(7 14 21 28 ...) % 7 = 0
	个位有7：(7 17 27 37 ...) % 10 = 7
	十位有7：(70 71 72 73 ...) / 10 = 7
*/

int main()
{
	for (int i = 1; i <= 100; i++)
	{
		if (i % 7 == 0 || i % 10 == 7 || i / 10 == 7)
		{
			cout << "Knock!" << endl;
		}
		else
		{
			cout << i << endl;
		}
	}

	system("pause");
	return 0;
}
