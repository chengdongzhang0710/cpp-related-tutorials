#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "Animal constructor is called" << endl;
	}

	// 利用虚析构可以解决父类指针释放子类对象时不干净的问题
	/*virtual ~Animal()
	{
		cout << "Animal destructor is called" << endl;
	}*/

	// 纯虚析构，需要声明也需要实现，和纯虚函数不同
	// 有了纯虚析构后，这个类也属于抽象类，无法实例化对象
	virtual ~Animal() = 0;

	virtual void speak() = 0;
};

Animal::~Animal()
{
	cout << "Animal destructor is called" << endl;
}

class Cat : public Animal
{
public:
	string* catName;

	Cat(string name)
	{
		cout << "Cat constructor is called" << endl;
		catName = new string(name);
	}

	~Cat()
	{
		if (catName != NULL)
		{
			cout << "Cat destructor is called" << endl;
			delete catName;
			catName = NULL;
		}
	}

	virtual void speak()
	{
		cout << *catName << " cat is speaking" << endl;
	}
};

void test1()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	// 父类指针在析构时不会调用子类中析构函数，导致子类如果有堆区属性，会出现内存泄露
	delete animal;
}

int main()
{
	test1();
	
	system("pause");
	return 0;
}
