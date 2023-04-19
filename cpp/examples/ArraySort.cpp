#include <iostream>
using namespace std;

template<typename T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			int temp = arr[i];
			arr[i] = arr[max];
			arr[max] = temp;
		}
	}
}

template<typename T>
void myPrint(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test1()
{
	char charArr[] = "badcfe";
	int num = sizeof(charArr) / sizeof(char);
	mySort<char>(charArr, num);
	myPrint<char>(charArr, num);
}

void test2()
{
	int intArr[] = { 7, 5, 1, 3, 9, 2, 4, 6, 8 };
	int num = sizeof(intArr) / sizeof(int);
	mySort<int>(intArr, num);
	myPrint<int>(intArr, num);
}

int main()
{
	test1();
	test2();

	system("pause");
	return 0;
}
