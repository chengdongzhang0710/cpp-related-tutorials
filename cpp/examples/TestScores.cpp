#include <iostream>
#include <string>
using namespace std;

int main()
{
	int scores[3][3] = { {100, 100, 100}, {90, 50, 100}, {60, 70, 80} };
	string names[3] = { "Zhang", "Li", "Wang" };
	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		for (int j = 0; j < 3; j++)
		{
			sum += scores[i][j];
		}
		cout << names[i] << "'s total score is " << sum << endl;
	}

	system("pause");
	return 0;
}
