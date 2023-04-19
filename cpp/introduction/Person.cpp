#include "Person.h"

template <typename T1, typename T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->personName = name;
	this->personAge = age;
}

template <typename T1, typename T2>
void Person<T1, T2>::show()
{
	cout << "Name: " << this->personName << " Age: " << this->personAge << endl;
}
