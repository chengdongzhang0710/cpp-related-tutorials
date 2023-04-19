#include <iostream>
#include <fstream>
using namespace std;

class Person
{
public:
	char personName[64];
	int personAge;
};

// 二进制文件-写文件
void test1()
{
	ofstream ofs("C:\\Users\\Chengdong Zhang\\Desktop\\person.txt", ios::out | ios::binary);
	//ofs.open("C:\\Users\\Chengdong Zhang\\Desktop\\person.txt", ios::out | ios::binary);
	Person p = { "Zhang", 18 };
	ofs.write((const char*)&p, sizeof(Person));
	ofs.close();
}

// 二进制文件-读文件
void test2()
{
	ifstream ifs("C:\\Users\\Chengdong Zhang\\Desktop\\person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "File cannot open" << endl;
		return;
	}
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << "Name: " << p.personName << endl;
	cout << "Age: " << p.personAge << endl;
	ifs.close();
}

int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}
