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
	void operator ++(int)//++�ں�
	{
		p = p->pNext;
	}

	bool operator !=(it<T> &myit)
	{
		return this->p != myit.p; 
	}

	void showdata()
	{
		cout << this->p->t << endl;//��ʾ����
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

