#include <iostream>
#include <map>
using namespace std;

void printMap(const map<int, int>& m)
{
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "Key = " << it->first << " Value = " << it->second << endl;
	}
}

void func()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;  // []不建议插入，但可以利用key访问到value

	//cout << m[5] << endl;

	printMap(m);
}

int main()
{
	func();
	
	system("pause");
	return 0;
}
