#include <iostream>
#include <string>
using namespace std;

class Building;

class NewFriend
{
public:
	Building* building;

	NewFriend();
	~NewFriend();
	void visit();
};

class Building
{
	// 全局函数做友元
	friend void goodFriend(Building* building);

	// 类做友元
	friend class GoodFriend;

	// 成员函数做友元
	friend void NewFriend::visit();

public:
	string buildingSittingRoom;

private:
	string buildingBedRoom;

public:
	Building()
	{
		buildingSittingRoom = "SittingRoom";
		buildingBedRoom = "BedRoom";
	}
};

NewFriend::NewFriend()
{
	building = new Building;
}

NewFriend::~NewFriend()
{
	delete building;
}

void NewFriend::visit()
{
	cout << "Function visit is accessing " << building->buildingSittingRoom << endl;
	cout << "Function visit is accessing " << building->buildingBedRoom << endl;
}

class GoodFriend
{
public:
	Building* building;

	GoodFriend();
	~GoodFriend();
	void visit();
};

GoodFriend::GoodFriend()
{
	building = new Building;
}

GoodFriend::~GoodFriend()
{
	delete building;
}

void GoodFriend::visit()
{
	cout << "Class GoodFriend is accessing " << building->buildingSittingRoom << endl;
	cout << "Class GoodFriend is accessing " << building->buildingBedRoom << endl;
}

void goodFriend(Building* building)
{
	cout << "Global function goodFriend is accessing " << building->buildingSittingRoom << endl;
	cout << "Global function goodFriend is accessing " << building->buildingBedRoom << endl;
}

void test1()
{
	Building building;
	goodFriend(&building);
}

void test2()
{
	GoodFriend gf;
	gf.visit();
}

void test3()
{
	NewFriend nf;
	nf.visit();
}

int main()
{
	//test1();

	//test2();

	test3();

	system("pause");
	return 0;
}
