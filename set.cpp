#include <iostream>
#include <set>
#include <vector>
#include "write.h"

using namespace std;

int main()
{
	vector<string> vs;
	set<string>ss;

	vs.push_back("asd");
	ss.insert("asd");
	vs.push_back("qwe");
	ss.insert("qwe");
	vs.push_back("tyu");
	ss.insert("tyu");
	vs.push_back("nenachadza");

	write_short(vs);
	write_short(ss);

	for(vector<string>::iterator it = vs.begin(); it != vs.end(); it++)
	{
		cout << *it << (ss.find(*it) != ss.end() ? " ano" : " nie") << endl;;
	}

	return 0;
}
