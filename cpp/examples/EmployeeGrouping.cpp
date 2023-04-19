#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

#define PLAN 0
#define ART 1
#define DEVELOP 2

class Employee
{
public:
	string m_name;
	int m_salary;
};

void createEmployee(vector<Employee>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Employee employee;
		employee.m_name = "Employee";
		employee.m_name += nameSeed[i];
		employee.m_salary = rand() % 10000 + 10000;  // 10000 ~ 19999
		v.push_back(employee);
	}
}

void groupEmployee(vector<Employee>& v, multimap<int, Employee>& m)
{
	for (vector<Employee>::iterator it = v.begin(); it != v.end(); it++)
	{
		int department = rand() % 3;  // 0, 1, 2
		m.insert(make_pair(department, *it));
	}
}

void showEmployee(multimap<int, Employee>& m)
{
	cout << "Plan Department:" << endl;
	multimap<int, Employee>::iterator pos = m.find(PLAN);
	int count = m.count(PLAN);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "Name: " << pos->second.m_name << " Salary: " << pos->second.m_salary << endl;
	}

	cout << "------------------------------" << endl;
	cout << "Art Department:" << endl;
	pos = m.find(ART);
	count = m.count(ART);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "Name: " << pos->second.m_name << " Salary: " << pos->second.m_salary << endl;
	}

	cout << "------------------------------" << endl;
	cout << "Develop Department:" << endl;
	pos = m.find(DEVELOP);
	count = m.count(DEVELOP);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "Name: " << pos->second.m_name << " Salary: " << pos->second.m_salary << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	vector<Employee> vec;
	createEmployee(vec);

	multimap<int, Employee> mp;
	groupEmployee(vec, mp);

	showEmployee(mp);
	
	system("pause");
	return 0;
}
