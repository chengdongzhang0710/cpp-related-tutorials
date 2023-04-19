#include <iostream>
#include <math.h>
using namespace std;

/*
1. 将所有的三位数进行输出(100~999)
2. 在所有三位数中找到水仙花数
	获取个位：对数字取模于10可以获取到个位
	获取十位：先整除于10，得到两位数，再取模于10，得到十位
	获取百位：直接整除于100，获取百位
	判断：个位^3 + 十位^3 + 百位^3 = 数本身
*/

int main()
{
	int num = 100;
	int a = 0;  // 个位
	int b = 0;  // 十位
	int c = 0;  // 百位
	do
	{
		a = num % 10;
		b = num / 10 % 10;
		c = num / 100;

		if (pow(a, 3) + pow(b, 3) + pow(c, 3) == num)
		{
			cout << num << endl;
		}

		num++;
	}
	while (num < 1000);

	system("pause");
	return 0;
}
