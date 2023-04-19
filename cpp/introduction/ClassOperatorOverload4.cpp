#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	string personName;
	int personAge;

	Person(string name, int age) : personName(name), personAge(age)
	{
	}

	bool operator==(Person& p)
	{
		return (this->personName == p.personName) && (this->personAge == p.personAge);
	}

	bool operator!=(Person& p)
	{
		return (this->personName != p.personName) || (this->personAge != p.personAge);
	}
};

void test1()
{
	Person p1("Tom", 18);
	Person p2("Bob", 18);

	if (p1 == p2)
	{
		cout << "p1 and p2 are equal" << endl;
	}
	
	if (p1 != p2)
	{
		cout << "p1 and p2 are not equal" << endl;
	}
}

int main()
{
	test1();
	
	system("pause");
	return 0;
}
