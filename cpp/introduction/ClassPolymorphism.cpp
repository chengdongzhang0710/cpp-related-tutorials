#include <iostream>
using namespace std;

class Animal
{
public:
	// 虚函数
	virtual void speak()
	{
		cout << "Animal is speaking" << endl;
	}
};

class Cat : public Animal
{
public:
	void speak()
	{
		cout << "Cat is speaking" << endl;
	}
};

class Dog : public Animal
{
public:
	void speak()
	{
		cout << "Dog is speaking" << endl;
	}
};

// 地址早绑定，在编译阶段确定函数地址
// 如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，即地址晚绑定
void doSpeak(Animal& animal)  // Animal& animal = cat
{
	animal.speak();  // 输出"Animal is speaking"
}

void test1()
{
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}

void test2()
{
	cout << "The size of class Animal: " << sizeof(Animal) << endl;
}

int main()
{
	//test1();
	test2();
	
	system("pause");
	return 0;
}
