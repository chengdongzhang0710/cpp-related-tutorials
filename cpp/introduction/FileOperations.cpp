#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// 写文件
void test1()
{
	ofstream ofs;
	ofs.open("C:\\Users\\Chengdong Zhang\\Desktop\\test.txt", ios::out);
	ofs << "Name: Zhang" << endl;
	ofs << "Gender: Male" << endl;
	ofs << "Age: 18" << endl;
	ofs.close();
}

// 读文件
void test2()
{
	ifstream ifs;
	ifs.open("C:\\Users\\Chengdong Zhang\\Desktop\\test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "File cannot open" << endl;
		return;
	}

	// 第一种
	/*char buffer[1024] = { 0 };
	while (ifs >> buffer)
	{
		cout << buffer << endl;
	}*/

	// 第二种
	/*char buffer[1024] = { 0 };
	while (ifs.getline(buffer, sizeof(buffer)))
	{
		cout << buffer << endl;
	}*/

	// 第三种
	/*string buffer;
	while (getline(ifs, buffer))
	{
		cout << buffer << endl;
	}*/

	// 第四种
	char c;
	while ((c = ifs.get()) != EOF)  // EOF-End Of Line
	{
		cout << c;
	}

	ifs.close();
}

int main()
{
	//test1();

	test2();

	system("pause");
	return 0;
}
