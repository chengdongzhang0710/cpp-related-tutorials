#include <iostream>
using namespace std;

class Animal
{
public:
	int age;
};

class Bear : virtual public Animal
{
};

class Cat : virtual public Animal
{
};

class Panda : public Bear, public Cat
{
};

void test1()
{
	Panda pd;
	pd.Bear::age = 18;
	pd.Cat::age = 28;

	cout << "pd.Bear::age = " << pd.Bear::age << endl;
	cout << "pd.Cat::age = " << pd.Cat::age << endl;
	cout << "pd.age = " << pd.age << endl;
}

int main()
{
	test1();

	system("pause");
	return 0;
}
