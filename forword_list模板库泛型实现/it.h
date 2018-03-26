#pragma once
#include"Node.h"

template<class T>
class it
{
private:
	Node<T>* p;
public:
	T operator *()
	{
		return p->t;
	}
	Node<T>* operator ->()
	{
		return p;
	}
	void operator ++()
	{
		p = p->pNext;
	}
	void operator ++(int)//++在后
	{
		p = p->pNext;
	}

	bool operator !=(it<T> &myit)
	{
		return this->p != myit.p; 
	}

	void showdata()
	{
		cout << this->p->t << endl;//显示数据
	}
	it(Node<T>*pnew) :p(pnew)
	{

	}



	it() :p(nullptr)
	{

	}
	~it()
	{
		if (p != nullptr)
		{
			//delete p;
		}
	}
};

