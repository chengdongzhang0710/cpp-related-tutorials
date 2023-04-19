#include <iostream>
#include <string>
using namespace std;

/*struct Student
{
	string name;
	int age;
	int score;
} s3;*/

struct Student
{
	string name;
	int age;
	int score;
};

struct Teacher
{
	int id;
	string name;
	int age;
	struct Student stu;
};

void printStudent(const Student* p)
{
	// p->age = 150;  // 错误
	cout << "Name: " << p->name << endl;
	cout << "Age: " << p->age << endl;
	cout << "Score: " << p->score << endl;
	return;
}

void printStudent1(Student s)
{
	s.age = 100;
	cout << "Name: " << s.name << endl;
	cout << "Age: " << s.age << endl;
	cout << "Score: " << s.score << endl;
	return;
}

void printStudent2(Student* p)
{
	p->age = 200;
	cout << "Name: " << p->name << endl;
	cout << "Age: " << p->age << endl;
	cout << "Score: " << p->score << endl;
	return;
}

int main()
{
	// 通过结构体创建变量
	/*struct Student s1;
	s1.name = "Zhang";
	s1.age = 18;
	s1.score = 100;
	cout << "Name: " << s1.name << endl;
	cout << "Age: " << s1.age << endl;
	cout << "Score: " << s1.score << endl;

	struct Student s2 = { "Li", 19, 80 };
	cout << "Name: " << s2.name << endl;
	cout << "Age: " << s2.age << endl;
	cout << "Score: " << s2.score << endl;

	s3.name = "Wang";
	s3.age = 20;
	s3.score = 60;
	cout << "Name: " << s3.name << endl;
	cout << "Age: " << s3.age << endl;
	cout << "Score: " << s3.score << endl;*/

	// 结构体数组
	/*struct Student stuArray[3] =
	{
		{"Zhang", 18, 100},
		{"Li", 19, 80},
		{"Wang", 20, 60}
	};
	stuArray[2].name = "Zhao";

	for (int i = 0; i < 3; i++)
	{
		cout << "Name: " << stuArray[i].name << endl;
		cout << "Age: " << stuArray[i].age << endl;
		cout << "Score: " << stuArray[i].score << endl;
	}*/

	// 结构体指针
	/*Student s = { "Zhang", 18, 100 };
	Student* p = &s;
	cout << "Name: " << p->name << endl;
	cout << "Age: " << p->age << endl;
	cout << "Score: " << p->score << endl;*/

	// 结构体嵌套结构体
	/*Teacher t;
	t.id = 10000;
	t.name = "Wang";
	t.age = 50;
	t.stu.name = "Xiao Wang";
	t.stu.age = 20;
	t.stu.score = 60;
	cout << "ID: " << t.id << endl;
	cout << "Name: " << t.name << endl;
	cout << "Age: " << t.age << endl;
	cout << "Student Name: " << t.stu.name << endl;
	cout << "Student Age: " << t.stu.age << endl;
	cout << "Student Score: " << t.stu.score << endl;*/

	// 结构体做函数参数
	Student stu = { "Zhang", 18, 100 };

	printStudent1(stu);
	cout << "Name: " << stu.name << endl;
	cout << "Age: " << stu.age << endl;
	cout << "Score: " << stu.score << endl;

	printStudent2(&stu);
	cout << "Name: " << stu.name << endl;
	cout << "Age: " << stu.age << endl;
	cout << "Score: " << stu.score << endl;

	// 结构体中const使用场景
	printStudent(&stu);

	system("pause");
	return 0;
}
