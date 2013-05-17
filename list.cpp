#include <iostream>

using namespace std;

class CList
{
	struct TElem
	{
		TElem(int v, TElem* n = NULL) : v(v), n(n) {}
		int v;
		TElem *n;
	};
	TElem *h, *t;
public:
	CList()
	{
		h = t = NULL;
	}
	CList(const CList& list)
	{
		h = t = NULL;
		TElem *tmp = list.h;
		while(tmp)
		{
			push_back(tmp->v);
			tmp = tmp->n;
		}
	}
	CList& operator=(const CList& list)
	{
		if(&list != this)
		{
			while(h)
			{
				TElem *tmp = h;
				h = h->n;
				delete tmp;
			}
			h = t = NULL;
			TElem *tmp = list.h;
			while(tmp)
			{
				push_back(tmp->v);
				tmp = tmp->n;
			}
		}
		return *this;
	}
	CList& push_back(int val)
	{
		if(h == NULL)
			h = t = new TElem(val);
		else
		{
			t->n = new TElem(val);
			t = t->n;
		}
		return *this;
	}
	CList& push_front(int val)
	{
		if(h == NULL)
			h = t = new TElem(val);
		else
		{
			TElem *tmp = new TElem(val, h);
			h = tmp;
		}
		return *this;
	}
	CList& insert_after(int v1, int v2)
	{
		TElem *tmp = h;
		while(tmp)
		{
			if(tmp->v == v1)
			{
				tmp->n = new TElem(v2, tmp->n);
			}
			tmp = tmp->n;
		}
		return *this;
	}
	CList& insert_before(int v1, int v2)
	{
		TElem *prev = NULL;
		TElem *tmp = h;
		while(tmp)
		{
			if(tmp->v == v1)
			{
				prev-> n = new TElem(v2, tmp);
			}
			prev = tmp;
			tmp = tmp->n;
		}
		return *this;
	}
	friend ostream& operator << (ostream& os, const CList& e)
	{
		TElem *tmp = e.h;
		while(tmp)
		{
			os << tmp->v << " ";
			tmp = tmp->n;
		}
		return os;
	}
	~CList()
	{
		while(h)
		{
			TElem *tmp = h;
			h = h->n;
			delete tmp;
		}
	}
};

int main()
{
	CList l;
	l.push_back(5)
	 .push_back(6)
	 .push_back(7)
	 .push_front(5)
	 .push_front(3)
	 .push_front(2)
	 .insert_after(5,100).
	 insert_before(100,99);
	cout << l << endl;

	CList m;
	m = l;
	cout << m << endl;
	return 0;
}
