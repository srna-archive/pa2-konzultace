#include <iostream>
#include <vector>
#include "write.h"

using namespace std;

int main()
{
	vector <int> v;
	v.push_back(7);
	for(int i = 0; i < 10 ; i++)
		v.push_back(i);
	v.push_back(5);

	// vloz na 3. poz cislo 5
	v.insert(v.begin()+2, 5);

	// za kazdu 5 daj 6
	for(vector<int>::iterator it = v.begin();
		it != v.end(); it++)
	{
		if(*it == 5)
			it = v.insert(++it, 6);
	}

	// zmaz kazdy vyskyt cisla 7
	for(vector<int>::iterator it = v.begin();
		it != v.end(); it++)
	{
		if(*it == 7)
			it = v.erase(it);
	}

	write_short(v);

	vector< vector < int > > matrix;
	matrix[0][0] = 1;

	// vector<int> w;
	// w.insert(w.begin(),-1);
	// for(int i = 0; i < 100 ; i++)
	// 	w.insert(w.end()-1, i);

	// write_short(w);

	return 0;
}
