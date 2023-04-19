#include <iostream>
using namespace std;

class Person
{
public:
	int* personAge;

	Person(int age)
	{
		personAge = new int(age);
	}

	~Person()
	{
		if (personAge != NULL)
		{
			delete personAge;
			personAge = NULL;
		}
	}

	Person& operator=(Person& p)
	{
		if (personAge != NULL)
		{
			delete personAge;
			personAge = NULL;
		}
		personAge = new int(*p.personAge);
		return *this;
	}
};

void test1()
{
	Person p1(18);
	Person p2(20);
	Person p3(30);

	p3 = p2 = p1;

	cout << "The age of p1 is " << *p1.personAge << endl;
	cout << "The age of p2 is " << *p2.personAge << endl;
	cout << "The age of p3 is " << *p3.personAge << endl;
}

int main()
{
	test1();

	system("pause");
	return 0;
}
