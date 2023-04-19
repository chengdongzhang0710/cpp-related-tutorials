#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Student
{
	string name;
	int score;
};

struct Teacher
{
	string name;
	Student sArray[5];
};

void allocateSpace(Teacher tArray[], int len)
{
	string nameSeed = "ABCDE";

	for (int i = 0; i < len; i++)
	{
		tArray[i].name = "Teacher_";
		tArray[i].name += nameSeed[i];
		for (int j = 0; j < 5; j++)
		{
			tArray[i].sArray[j].name = "Student_";
			tArray[i].sArray[j].name += nameSeed[j];
			int random = rand() % 61 + 40;  // 40~100
			tArray[i].sArray[j].score = random;
		}
	}

	return;
}

void printInfo(Teacher tArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "Teacher Name: " << tArray[i].name << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\tStudent Name: " << tArray[i].sArray[j].name << "  ";
			cout << "Student Score: " << tArray[i].sArray[j].score << "  ";
			cout << endl;
		}
	}
	
	return;
}

int main()
{
	srand((unsigned int)time(NULL));

	Teacher tArray[3];
	int len = sizeof(tArray) / sizeof(tArray[0]);

	allocateSpace(tArray, len);

	printInfo(tArray, len);

	system("pause");
	return 0;
}
