#include "MyArray.hpp"

void printIntArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test1()
{
	MyArray<int> arr1(5);
	MyArray<int> arr2(arr1);
	MyArray<int> arr3(100);
	arr3 = arr1;
}

void test2()
{
	MyArray<int> arr1(5);
	for (int i = 0; i < 5; i++)
	{
		arr1.pushBack(i);
	}
	cout << "arr1: ";
	printIntArray(arr1);
	cout << "The capacity of arr1 is " << arr1.getCapacity() << endl;
	cout << "The size of arr1 is " << arr1.getSize() << endl;

	MyArray<int> arr2(arr1);
	arr2.popBack();
	cout << "arr2: ";
	printIntArray(arr2);
	cout << "The capacity of arr2 is " << arr2.getCapacity() << endl;
	cout << "The size of arr2 is " << arr2.getSize() << endl;
}

int main()
{
	//test1();
	test2();
	
	system("pause");
	return 0;
}
