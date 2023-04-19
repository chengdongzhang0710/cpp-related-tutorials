#include <iostream>
#include <string>
#include <list>
using namespace std;

class Person
{
public:
	string m_name;
	int m_age;
	int m_height;

	Person(string name, int age, int height) : m_name(name), m_age(age), m_height(height)
	{
	}
};

void printList(const list<Person>& l)
{
	for (list<Person>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "Name: " << it->m_name << " Age: " << it->m_age << " Height: " << it->m_height << endl;
	}
}

bool compare(Person& p1, Person& p2)
{
	if (p1.m_age == p2.m_age)
	{
		return p1.m_height > p2.m_height;
	}
	return p1.m_age < p2.m_age;
}

void func()
{
	list<Person> l;

	Person p1("Liu", 35, 175);
	Person p2("Cao", 45, 180);
	Person p3("Sun", 40, 170);
	Person p4("Zhao", 25, 190);
	Person p5("Zhang", 35, 160);
	Person p6("Guan", 35, 200);

	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);

	cout << "Before Sort:" << endl;
	printList(l);

	cout << "------------------------------" << endl;
	cout << "After Sort:" << endl;
	l.sort(compare);
	printList(l);
}

int main()
{
	func();
	
	system("pause");
	return 0;
}
