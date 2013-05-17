#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "write.h"

using namespace std;

class Person
{
	string name;
	int age;
public:
	Person(string name, int age) : name(name), age(age) {}
	friend ostream& operator<<(ostream& os, const Person& p)
	{
		os << p.name << "(" << p.age << " let)";
		return os;
	}
	friend class PersonAgeComparator;
	friend class PersonNameComparator;
};

class PersonAgeComparator
{
public:
	bool operator()(const Person& p1, const Person& p2)
	{
		return p1.age < p2.age;
	}
};

class PersonNameComparator
{
public:
	bool operator()(const Person& p1, const Person& p2)
	{
		return p1.name < p2.name;
	}
};

int main()
{
	map<Person,int,PersonAgeComparator> bodyByAge;
	bodyByAge[Person("Asd", 20)] = 20;
	bodyByAge[Person("Fgh", 15)] = 30;
	bodyByAge[Person("Qwe", 40)] = 10;
	write(cout, "\n", bodyByAge.begin(), bodyByAge.end());
	cout << endl;

	cout << "---" << endl;

	map<Person,int,PersonNameComparator> bodyByName;
	bodyByName[Person("Asd", 20)] = 20;
	bodyByName[Person("Fgh", 15)] = 30;
	bodyByName[Person("Qwe", 40)] = 10;
	write(cout, "\n", bodyByName.begin(), bodyByName.end());
	cout << endl;

	cout << "---" << endl;

	vector<Person> bodyVector;
	bodyVector.push_back(Person("Asd", 20));
	bodyVector.push_back(Person("Fgh2", 15));
	bodyVector.push_back(Person("Fgh", 15));
	bodyVector.push_back(Person("Qwe", 40));
	write(cout, "\n", bodyVector.begin(), bodyVector.end());
	cout << endl;

	cout << "---" << endl;
	stable_sort(bodyVector.begin(), bodyVector.end(), PersonAgeComparator());
	write(cout, "\n", bodyVector.begin(), bodyVector.end());
	cout << endl;

	cout << "---" << endl;
	bool jeMladsi = PersonAgeComparator()(Person("Asd", 20), Person("Fgh2", 15));
	cout << "Je mladsi? " << (jeMladsi ? "ano" : "ne") << endl;

	return 0;
}
