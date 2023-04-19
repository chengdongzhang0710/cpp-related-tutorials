#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

using namespace std;

class Person
{
public:
    string m_name;
    int m_score;

    Person(string name, int score) : m_name(name), m_score(score)
    {
    }
};

void createPerson(vector<Person>& v)
{
    string nameSeed = "ABCDE";

    for (int i = 0; i < 5; i++)
    {
        string name = "Player";
        name += nameSeed[i];

        int score = 0;

        Person p(name, score);

        v.push_back(p);
    }
}

void setScore(vector<Person>& v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        deque<int> d;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60;
            d.push_back(score);
        }

        cout << it->m_name << endl;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            cout << *dit << " ";
        }
        cout << endl;

        sort(d.begin(), d.end());

        d.pop_back();
        d.pop_front();

        int sum = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            sum += *dit;
        }
        int avg = sum / d.size();

        it->m_score = avg;
    }
}

void showScore(vector<Person>& v)
{
    cout << "----------------------------------------" << endl;
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "Name: " << it->m_name << " Score: " << it->m_score << endl;
    }
}

int main()
{
    srand((unsigned int)time(NULL));

    vector<Person> v;
    createPerson(v);
    setScore(v);
    showScore(v);

    system("pause");
    return 0;
}
