#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	int personAge;

	// 构造函数
	Person()
	{
		cout << "Person constructor without parameters is called!" << endl;
	}

	Person(int age)
	{
		personAge = age;
		cout << "Person constructor with parameters is called!" << endl;
	}

	// 拷贝构造函数
	Person(const Person &p)
	{
		personAge = p.personAge;
		cout << "Person constructor using copy is called!" << endl;
	}

	// 析构函数
	~Person()
	{
		cout << "Person destructor is called!" << endl;
	}
};

class P
{
public:
	int pAge;

	P()
	{
		cout << "P constructor without parameters is called!" << endl;
	}

	P(int age)
	{
		pAge = age;
		cout << "P constructor with parameters is called!" << endl;
	}

	/*P(const P& p)
	{
		pAge = p.pAge;
		cout << "P constructor using copy is called!" << endl;
	}*/

	~P()
	{
		cout << "P destructor is called!" << endl;
	}
};

class NewPerson
{
public:
	int pAge;
	int *pHeight;

	NewPerson(int age, int height)
	{
		pAge = age;
		pHeight = new int(height);
		cout << "NewPerson constructor with parameters is called!" << endl;
	}

	NewPerson(const NewPerson &np)
	{
		pAge = np.pAge;
		// pHeight = np.pHeight;  // 编译器默认实现就是这行代码
		pHeight = new int(*np.pHeight);
		cout << "NewPerson constructor using copy is called!" << endl;
	}

	~NewPerson()
	{
		// 析构代码，将堆区开辟数据做释放操作
		if (pHeight != NULL)
		{
			delete pHeight;
			pHeight = NULL;
		}
		cout << "NewPerson destructor is called!" << endl;
	}
};

class C
{
public:
	int cA;
	int cB;
	int cC;

	// 传统初始化操作
	/*C(int a, int b, int c)
	{
		cA = a;
		cB = b;
		cC = c;
	}*/

	// 初始化列表初始化属性
	C(int a, int b, int c) : cA(a), cB(b), cC(c)
	{
	}
};

class Phone
{
public:
	string phoneBrand;

	Phone(string brand)
	{
		phoneBrand = brand;
		cout << "Phone constructor is called!" << endl;
	}

	~Phone()
	{
		cout << "Phone destructor is called!" << endl;
	}
};

class Contact
{
public:
	string contactName;
	Phone contactPhone;

	// Phone contactPhone = brand  隐式转换法
	Contact(string name, string brand) : contactName(name), contactPhone(brand)
	{
		cout << "Contact constructor is called!" << endl;
	}

	~Contact()
	{
		cout << "Contact destructor is called!" << endl;
	}
};

class StaticPerson
{
public:
	static int personVar;
	int personVar2;

	static void func()
	{
		personVar = 200; // 静态成员函数可以访问静态成员变量
		// personVar2 = 200;  // 错误！静态成员函数不可以访问非静态成员变量，无法区分是哪个对象的personVar2
		cout << "static void func is called!" << endl;
	}
};

int StaticPerson::personVar = 100;

void test1()
{
	// Person p;

	// 构造函数调用
	// 括号法
	// 注意！调用默认构造函数时不要加括号
	Person p1;	   // 默认构造函数调用
	Person p2(10); // 有参构造函数调用
	Person p3(p2); // 拷贝构造函数调用
	// Person p4();  // 编译器会认为这是一个函数的声明

	cout << "p2's age is " << p2.personAge << endl;
	cout << "p3's age is" << p3.personAge << endl;

	// 显式法
	// 注意！不要利用拷贝构造函数初始化匿名对象
	Person p5;
	Person p6 = Person(10); // Person(10) 匿名对象，特点是当前行执行结束后，系统会立即回收掉匿名对象
	Person p7 = Person(p6);
	/*Person(10);
	cout << "After Person(10)" << endl;*/
	// Person(p6);  // 编译器会认为Person(p6)等价于Person p6，是一个对象声明

	// 隐式转换法
	Person p8 = 10; // 相当于Person p8 = Person(10)
	Person p9 = p8;
}

// 值传递的方式给函数参数传值
void func2(Person p)
{
}

void test2()
{
	Person p;
	func2(p);
}

// 值方式返回局部对象
Person func3()
{
	Person p1;
	cout << &p1 << endl;
	return p1;
}

void test3()
{
	Person p = func3();
	cout << &p << endl;
}

void test4()
{
	P p1;
	p1.pAge = 18;

	P p2(p1);
	cout << "p2's age is " << p2.pAge << endl;
}

void test5()
{
	P p1(28);
	P p2(p1);

	cout << "p2's age is " << p2.pAge << endl;
}

void test6()
{
	NewPerson np1(18, 160);
	cout << "np1's age is " << np1.pAge << " and np1's height is " << *np1.pHeight << endl;

	NewPerson np2(np1);
	cout << "np2's age is " << np2.pAge << " and np2's height is " << *np2.pHeight << endl;
}

void test7()
{
	C c(30, 20, 10);
	cout << "cA = " << c.cA << endl;
	cout << "cB = " << c.cB << endl;
	cout << "cC = " << c.cC << endl;
}

void test8()
{
	Contact contact("Zhang", "Apple");

	cout << contact.contactName << " owns " << contact.contactPhone.phoneBrand << endl;
}

void test9()
{
	StaticPerson p1;
	cout << p1.personVar << endl;

	StaticPerson p2;
	p2.personVar = 200;
	cout << p1.personVar << endl;
}

void test10()
{
	StaticPerson p;
	cout << p.personVar << endl;

	cout << StaticPerson::personVar << endl;
}

void test11()
{
	StaticPerson p;
	p.func();

	StaticPerson::func();
}

int main()
{
	// Person p;
	// test1();

	// test2();
	// test3();

	// test4();
	// test5();

	// test6();

	// test7();

	// test8();

	// test9();
	// test10();
	test11();

	system("pause");
	return 0;
}
