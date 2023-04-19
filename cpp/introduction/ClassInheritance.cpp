#include <iostream>
using namespace std;

class Base
{
public:
	int baseVarA;

protected:
	int baseVarB;

private:
	int baseVarC;
};

class Son : public Base
{
public:
	int sonVarD;
};

void test1()
{
	cout << "The size of class Son is " << sizeof(Son) << endl;
}

int main()
{
	test1();

	system("pause");
	return 0;
}
