#include <iostream>
using namespace std;

// 地址传递
void swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main()
{
	// 指针的定义和使用
	/*int a = 10;
	int* p;
	p = &a;
	cout << "The address of a is " << &a << endl;
	cout << "p is " << p << endl;

	*p = 1000;
	cout << "a = " << a << endl;
	cout << "*p = " << *p << endl;*/

	// 指针所占内存空间
	/*int a = 10;
	int* p = &a;
	cout << "sizeof int* = " << sizeof(p) << endl;
	cout << "sizeof float* = " << sizeof(float*) << endl;
	cout << "sizeof double* = " << sizeof(double*) << endl;
	cout << "sizeof char* = " << sizeof(char*) << endl;*/

	// 空指针
	/*int* p = NULL;
	cout << *p << endl;  // 错误！*/

	// 野指针
	/*int* p = (int*)0x1100;
	cout << *p << endl;  // 错误！*/

	// const修饰指针
	/*int a = 10;
	int b = 10;*/

	// 常量指针
	/*const int* p = &a;
	*p = 20;  // 错误，指针指向的值不可以改
	p = &b;  // 正确，指针指向可以改*/

	// 指针常量
	/*int* const p = &a;
	*p = 20;  // 正确，指针指向的值可以改
	p = &b;  // 错误，指针指向不可以改*/

	// const既修饰指针又修饰常量
	/*const int* const p = &a;
	*p = 20;  // 错误
	p = &b;  // 错误*/

	// 指针和数组
	/*int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int* p = arr;
	cout << "The first element is " << *p << endl;
	p++;  // 让指针向后偏移4个字节
	cout << "The second element is " << *p << endl;

	int* p2 = arr;
	cout << "The array is: ";
	for (int i = 0; i < 10; i++)
	{
		cout << *p2 << ' ';
		p2++;
	}
	cout << endl;*/

	// 指针和函数
	int a = 10;
	int b = 20;
	swap(&a, &b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	system("pause");
	return 0;
}
