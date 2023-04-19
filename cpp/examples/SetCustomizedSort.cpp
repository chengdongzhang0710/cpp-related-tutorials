#include <iostream>
#include <string>
#include <set>
using namespace std;

class Person
{
public:
	string m_name;
	int m_age;

	Person(string name, int age) : m_name(name), m_age(age)
	{
	}
};

class Compare
{
public:
	bool operator()(const Person& p1, const Person& p2) const
	{
		return p1.m_age > p2.m_age;
	}
};

void func()
{
	set<Person, Compare> s;

	Person p1("Liu", 24);
	Person p2("Guan", 28);
	Person p3("Zhang", 25);
	Person p4("Zhao", 21);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person, Compare>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "Name: " << it->m_name << " Age: " << it->m_age << endl;
	}
}

int main()
{
	func();
	
	system("pause");
	return 0;
}
