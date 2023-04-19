#include <iostream>
using namespace std;

class Person
{
public:
	int personVar1;
	int personVar2;

	// 成员函数重载
	/*Person operator+(Person& p)
	{
		Person temp;
		temp.personVar1 = this->personVar1 + p.personVar1;
		temp.personVar2 = this->personVar2 + p.personVar2;
		return temp;
	}*/
};

// 全局函数重载
Person operator+(Person& p1, Person& p2)
{
	Person temp;
	temp.personVar1 = p1.personVar1 + p2.personVar1;
	temp.personVar2 = p1.personVar2 + p2.personVar2;
	return temp;
}

Person operator+(Person& p1, int num)
{
	Person temp;
	temp.personVar1 = p1.personVar1 + num;
	temp.personVar2 = p1.personVar2 + num;
	return temp;
}

ostream& operator<<(ostream& out, Person& p)
{
	out << "personVar1 = " << p.personVar1 << " personVar2 = " << p.personVar2;
	return out;
}

void test1()
{
	Person p1, p2;
	p1.personVar1 = 10;
	p1.personVar2 = 10;
	p2.personVar1 = 10;
	p2.personVar2 = 10;

	Person p3 = p1 + p2;
	//Person p3 = p1.operator+(p2);  // 成员函数重载本质调用
	//Person p3 = operator+(p1, p2);  // 全局函数重载本质调用
	
	// 运算符重载也可以发生函数重载
	Person p4 = p1 + 100;

	cout << "p3.personVar1 = " << p3.personVar1 << endl;
	cout << "p3.personVar2 = " << p3.personVar2 << endl;
	cout << "p4.personVar1 = " << p4.personVar1 << endl;
	cout << "p4.personVar2 = " << p4.personVar2 << endl;
}

void test2()
{
	Person p;
	p.personVar1 = 10;
	p.personVar2 = 10;

	cout << p << endl;
}

int main()
{
	//test1();

	test2();

	system("pause");
	return 0;
}
