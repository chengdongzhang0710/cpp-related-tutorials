#include <iostream>
#include <string>
using namespace std;

struct Hero
{
	string name;
	int age;
	string gender;
};

void bubbleSort(Hero heroArray[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (heroArray[j].age > heroArray[j + 1].age)
			{
				Hero temp = heroArray[j];
				heroArray[j] = heroArray[j + 1];
				heroArray[j + 1] = temp;
			}
		}
	}

	return;
}

void printInfo(Hero heroArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "Name: " << heroArray[i].name << "  ";
		cout << "Age: " << heroArray[i].age << "  ";
		cout << "Gender: " << heroArray[i].gender << "  ";
		cout << endl;
	}

	return;
}

int main()
{
	Hero heroArray[5] =
	{
		{"Liu Bei", 23, "Male"},
		{"Guan Yu", 22, "Male"},
		{"Zhang Fei", 20, "Male"},
		{"Zhao Yun", 21, "Male"},
		{"Diao Chan", 19, "Female"}
	};
	int len = sizeof(heroArray) / sizeof(heroArray[0]);

	cout << "Before:" << endl;
	printInfo(heroArray, len);

	bubbleSort(heroArray, len);

	cout << "After" << endl;
	printInfo(heroArray, len);

	system("pause");
	return 0;
}
