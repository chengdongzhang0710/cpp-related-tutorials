#include <iostream>
using namespace std;

class Person
{
	int personVar1;        // 非静态成员变量属于类的对象上
	static int personVar2; // 静态成员变量不属于类对象上

	void func()
	{
	}         // 非静态成员函数不属于类对象上
	static void func2()
	{
	} // 静态成员函数不属于类对象上
};

int Person::personVar2 = 0;

class NewPerson
{
public:
	int age;

	NewPerson(int age)
	{
		// age = age;  // 错误！
		this->age = age;
	}

	void PersonAddAge(NewPerson& p)
	{
		this->age += p.age;
	}

	NewPerson& PersonAddAge2(NewPerson& p)
	{
		this->age += p.age;
		return *this;
	}

	NewPerson PersonAddAge3(NewPerson& p)
	{
		this->age += p.age;
		return *this;
	}
};

class Person2
{
public:
	int personAge;

	void showClassName()
	{
		cout << "This is Person2 class" << endl;
	}

	void showPersonAge()
	{
		if (this == NULL)
		{
			return;
		}

		cout << "The age of Person2 is " << personAge << endl;
		//cout << "The age of Person2 is " << this->personAge << endl;  // 等价
	}
};

class Person3
{
public:
	int personVar;
	mutable int personVar2;  // 特殊变量，即使在常函数中也可以修改这个值

	// this指针的本质是指针常量，指针的指向是不可以修改的
	// 在成员函数后面加const，修饰的是this指向，让指针指向的值也不可以修改
	// 等价于const Person3* const this;
	void showPerson() const
	{
		//this->personVar = 100;  // 错误！
		//this = NULL;  // 错误！this指针不可以修改指针的指向
		personVar2 = 100;
	}

	void func()
	{
		personVar = 100;
	}
};

void test1()
{
	Person p;

	cout << "size of p = " << sizeof(p) << endl;
}

void test2()
{
	NewPerson p1(18);
	cout << "The age of p1 is " << p1.age << endl;
}

void test3()
{
	NewPerson p1(10);
	NewPerson p2(10);

	p2.PersonAddAge(p1);
	cout << "The age of p2 is " << p2.age << endl;

	// 链式编程思想
	p2.PersonAddAge2(p1).PersonAddAge2(p1);
	cout << "The age of p2 is " << p2.age << endl;

	p2.PersonAddAge3(p1).PersonAddAge3(p1);
	cout << "The age of p2 is " << p2.age << endl;
}

void test4()
{
	Person2* p = NULL;

	p->showClassName();

	//p->showPersonAge();  // 错误！原因是传入的指针为NULL
}

void test5()
{
	Person3 p;
	p.showPerson();
}

void test6()
{
	const Person3 p;  // 常对象，在对象前加const
	//p.personVar = 100;  // 错误！
	p.personVar2 = 100;  // 特殊变量，在常对象下也可以修改
	p.showPerson();
	//p.func();  // 错误！常对象不可以调用普通成员函数，因为普通成员函数可以修改属性
}

int main()
{
	//test1();

	//test2();
	//test3();

	//test4();

	//test5();
	test6();

	system("pause");
	return 0;
}
