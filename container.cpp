#include <iostream>
#include <vector>
#include <list>
#include <map>
#include "write.h"

using namespace std;

int main()
{
	vector <int> v;
	for(int i = 0; i < 10 ; i++)
		v.push_back(i);
	write(cout, ",", v.begin(), v.end());

	cout << endl;

	list <int> l;
	for(int i = 0; i < 10 ; i++)
		l.push_front(i);
	write(cout, ",", l.begin(), l.end());

	cout << endl;

	map <string, int> m;
	m["jedna"] = 1;
	m["dva"] = 2;
	m["tri"] = 3;
	write(cout, "\n", m.begin(), m.end());

	cout << endl;

}
