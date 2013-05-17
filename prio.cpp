#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "write.h"

using namespace std;

class Person
{
	string name, rank;
	int order;
public:
	Person(string name, string rank, int order) : name(name), rank(rank), order(order) {}
	friend ostream& operator<<(ostream& os, const Person& p)
	{
		os << p.name << " (" << p.rank << ", " << p.order <<")";
		return os;
	}
	friend class PersonRankComparator;
	friend class PersonOrderComparator;
};

class PersonOrderComparator
{
public:
	bool operator()(const Person& p1, const Person& p2)
	{
		return p1.order < p2.order;
	}
};

class PersonRankComparator
{
	map<string,int> ranks;
public:
	PersonRankComparator()
	{
		ranks["Admiral"] = 0;
		ranks["Captain"] = 1;
		ranks["Commander"] = 2;
	}
	bool operator()(const Person& p1, const Person& p2)
	{
		return ranks[p1.rank] < ranks[p2.rank];
	}
};

int main()
{
	vector<Person> people;
	people.push_back(Person("Kapitan", "Captain", 2));
	people.push_back(Person("Prikazca", "Commander", 1));
	people.push_back(Person("Admiral", "Admiral", 1));
	people.push_back(Person("First Kapitan", "Captain", 1));

	stable_sort(people.begin(), people.end(), PersonOrderComparator());
	stable_sort(people.begin(), people.end(), PersonRankComparator());

	write(cout, "\n", people.begin(), people.end());
	cout << endl;

	return 0;
}
