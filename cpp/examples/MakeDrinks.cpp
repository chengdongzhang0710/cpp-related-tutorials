#include <iostream>
using namespace std;

class AbstractDrinks
{
public:
	virtual void boil() = 0;
	virtual void brew() = 0;
	virtual void pour() = 0;
	virtual void add() = 0;
	virtual void makeDrink()
	{
		boil();
		brew();
		pour();
		add();
	}
};

class Coffee : public AbstractDrinks
{
	virtual void boil()
	{
		cout << "Boil water" << endl;
	}

	virtual void brew()
	{
		cout << "Brew coffee" << endl;
	}

	virtual void pour()
	{
		cout << "Pour in cup" << endl;
	}

	virtual void add()
	{
		cout << "Add sugar and milk" << endl;
	}
};

class Tea : public AbstractDrinks
{
	virtual void boil()
	{
		cout << "Boil water" << endl;
	}

	virtual void brew()
	{
		cout << "Brew tea" << endl;
	}

	virtual void pour()
	{
		cout << "Pour in cup" << endl;
	}

	virtual void add()
	{
		cout << "Add lemon" << endl;
	}
};

void doWork(AbstractDrinks* abs)
{
	abs->makeDrink();
	delete abs;
}

void test1()
{
	doWork(new Coffee);
	cout << "----------" << endl;
	doWork(new Tea);
}

int main()
{
	test1();
	
	system("pause");
	return 0;
}
