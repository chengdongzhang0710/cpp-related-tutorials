#include <iostream>
#include <string>
using namespace std;

#define PI 3.14

class Circle
{
public:
	int radius;

	double calcPerimeter()
	{
		return 2 * PI * radius;
	}
};

class Student
{
private:
	string stuName;
	int stuId;

public:
	void setInfo(string name, int id)
	{
		stuName = name;
		stuId = id;
	}

	void showInfo()
	{
		cout << "Name: " << stuName << '\t';
		cout << "ID: " << stuId << endl;
	}
};

class Person
{
public:
	string name;

protected:
	string car;

private:
	int password;

public:
	void func()
	{
		name = "Zhang";
		car = "Truck";
		password = 123456;
	}
};

class C1
{
	int a;
};

struct C2
{
	int a;
};

class Human
{
private:
	string humanName;  // 可读可写
	int humanAge;  // 可读可写
	string humanLover;  // 只写

public:
	void setName(string name)
	{
		humanName = name;
	}

	string getName()
	{
		return humanName;
	}

	void setAge(int age)
	{
		if (age < 0 || age > 150)
		{
			humanAge = 0;
			cout << "Invalid input!" << endl;
			return;
		}
		humanAge = age;
	}

	int getAge()
	{
		return humanAge;
	}

	void setLover(string lover)
	{
		humanLover = lover;
	}
};

class Cube
{
private:
	int cubeLength;
	int cubeWidth;
	int cubeHeight;

public:
	void setCube(int length, int width, int height)
	{
		cubeLength = length;
		cubeWidth = width;
		cubeHeight = height;
	}

	int getLength()
	{
		return cubeLength;
	}

	int getWidth()
	{
		return cubeWidth;
	}

	int getHeight()
	{
		return cubeHeight;
	}

	int calcSurfaceArea()
	{
		return 2 * (cubeLength * cubeWidth + cubeLength * cubeHeight + cubeWidth * cubeHeight);
	}

	int calcVolume()
	{
		return cubeLength * cubeWidth * cubeHeight;
	}

	bool isSame(Cube& c)
	{
		if (cubeLength == c.getLength() && cubeWidth == c.getWidth() && cubeHeight == c.getHeight())
		{
			return true;
		}
		return false;
	}
};

bool isCubeSame(Cube& c1, Cube& c2)
{
	if (c1.getLength() == c2.getLength() && c1.getWidth() == c2.getWidth() && c1.getHeight() == c2.getHeight())
	{
		return true;
	}
	return false;
}

int main()
{
	Circle circle;
	circle.radius = 10;
	cout << "The perimeter of the circle is " << circle.calcPerimeter() << endl;

	Student student;
	student.setInfo("Zhang", 1);
	student.showInfo();

	Person person;
	person.name = "Li";
	//person.car = "Benz";  // 错误，保护权限内容
	//person.password = 123;  // 错误，私有权限内容

	C1 c1;
	C2 c2;
	//c1.a = 10;  // 错误
	c2.a = 10;

	Human human;
	human.setName("Zhang");
	human.setAge(1000);
	human.setLover("Zhao");

	cout << "Name: " << human.getName() << endl;
	cout << "Age: " << human.getAge() << endl;

	Cube cube1;
	cube1.setCube(10, 10, 10);

	Cube cube2;
	cube2.setCube(10, 10, 10);

	cout << "Surface area: " << cube1.calcSurfaceArea() << endl;
	cout << "Volume: " << cube1.calcVolume() << endl;
	cout << (isCubeSame(cube1, cube2) ? "cube1 and cube2 are same" : "cube1 and cube2 are different") << endl;
	cout << (cube1.isSame(cube2) ? "cube1 and cube2 are same" : "cube1 and cube2 are different") << endl;

	system("pause");
	return 0;
}
