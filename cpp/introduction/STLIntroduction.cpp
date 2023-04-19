#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void myPrint(int val)
{
	cout << val << endl;
}

void test1()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	// 第一种遍历方式
	vector<int>::iterator itBegin = v.begin();  // 起始迭代器，指向容器中第一个元素
	vector<int>::iterator itEnd = v.end();  // 结束迭代器，指向容器中最后一个元素的下一个位置
	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}

	// 第二种遍历方式
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	// 第三种遍历方式，利用STL提供的遍历算法
	for_each(v.begin(), v.end(), myPrint);  // 回调函数的技术
}

class Person
{
public:
	string personName;
	int personAge;

	Person(string name, int age) : personName(name), personAge(age)
	{
	}
};

void test2()
{
	vector<Person> v;
	Person p1("A", 10);
	Person p2("B", 12);
	Person p3("C", 14);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "Name: " << it->personName << endl;
		cout << "Age: " << it->personAge << endl;
	}
}

void test3()
{
	vector<Person*> v;
	Person p1("A", 10);
	Person p2("B", 12);
	Person p3("C", 14);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "Name: " << (*it)->personName << endl;
		cout << "Age: " << (*it)->personAge << endl;
	}
}

void test4()
{
	vector<vector<int>> v;

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;

	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
	}

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}
}

int main()
{
	//test1();

	//test2();
	//test3();

	test4();

	system("pause");
	return 0;
}
