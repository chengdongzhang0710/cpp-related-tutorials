#include "BubbleSortFunction.h"

int main()
{
	int arr[] = { 4, 3, 6, 9, 1, 2, 10, 8, 7, 5 };
	int len = sizeof(arr) / sizeof(arr[0]);

	cout << "Before:" << endl;
	printArray(arr, len);

	bubbleSort(arr, len);

	cout << "After:" << endl;
	printArray(arr, len);

	system("pause");
	return 0;
}
