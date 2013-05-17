#include <iostream>

using namespace std;

template<class Iterator>
void write(ostream& os, string delim, 
	Iterator begin, Iterator end)
{
	for(Iterator it = begin; it != end;
		++it)
	{
		os << (*it);
		if(++it != end)
		{
			os << delim;
			--it;
		}
		else
			break;
	}
}

template <class T>
void write_short(const T& t)
{
	write(cout, ",", t.begin(), t.end());
	cout << endl;
}

template <class K, class V>
ostream& operator<<(ostream& os, const pair<K, V>& p)
{
	os << p.first << ": " << p.second;
	return os;
}