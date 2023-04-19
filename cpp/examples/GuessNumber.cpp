#include <iostream>
#include <ctime>  // time系统时间头文件包含
using namespace std;

int main()
{
	// 添加随机数种子，作用是利用当前系统时间生成随机数，防止每次随机数都一样
	srand((unsigned int)time(NULL));

	int num = rand() % 100 + 1;  // 生成0和1之间的随机数

	int val = 0;

	cout << "Guess the number:" << endl;

	while (val != num)
	{
		cin >> val;
		if (val > num)
		{
			cout << "Bigger! Guess again:" << endl;
		}
		else if (val < num)
		{
			cout << "Smaller! Guess again:" << endl;
		}
	}
	cout << "Right!" << endl;

	system("pause");
	return 0;
}
