#include <iostream>
using namespace std;

int main()
{
	int arr[] = { 1, 3, 2, 5, 4 };
	int start = 0;
	int end = sizeof(arr) / sizeof(arr[0]) - 1;
	int temp = 0;
	while (start < end)
	{
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
	cout << "The reversed array is ";
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
