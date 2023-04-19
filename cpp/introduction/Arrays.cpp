#include <iostream>
using namespace std;

int main()
{
	int arr[5] = { 10, 20, 30 };
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}

	cout << "The RAM size of the entire array is " << sizeof(arr) << endl;
	cout << "The RAM size of each element is " << sizeof(arr[0]) << endl;
	cout << "The number of array elements is " << sizeof(arr) / sizeof(arr[0]) << endl;

	cout << "The head address of the array is " << (int)arr << endl;
	cout << "The address of the first element is " << (int)&arr[0] << endl;
	cout << "The address of the second element is " << (int)&arr[1] << endl;

	int arr2[][4] = { 1, 2, 3, 4, 5, 6 };
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << arr2[i][j] << ' ';
		}
		cout << endl;
	}

	cout << "The RAM size of the entire 2d array is " << sizeof(arr2) << endl;
	cout << "The RAM size of each row is " << sizeof(arr2[0]) << endl;
	cout << "The RAM size of each element is " << sizeof(arr2[0][0]) << endl;
	cout << "The number of rows is " << sizeof(arr2) / sizeof(arr2[0]) << endl;
	cout << "The number of columns is " << sizeof(arr2[0]) / sizeof(arr2[0][0]) << endl;

	cout << "The head address of the 2d array is " << (int)arr2 << endl;
	cout << "The head address of the first row is " << (int)arr2[0] << endl;
	cout << "The address of the first element is " << (int)&arr2[0][0] << endl;
	cout << "The head address of the second row is " << (int)arr2[1] << endl;

	system("pause");
	return 0;
}
