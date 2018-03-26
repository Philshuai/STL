#include "forword_list.h"

template<class T>
forword_list<T>::forword_list() :phead(nullptr)
{

}

template<class T>
void forword_list<T>::clear()
{
	if (this->phead == nullptr)
	{
		return;
	}
	else
	{
		Node<T> *p1, *p2;
		p1 = this->phead;
		while (p1 != nullptr)
		{
			p2 = p1->pNext;
			delete p1;
			p1 = p2;
		}
		delete phead;
		phead = nullptr;//清空
	}
}

template<class T>
forword_list<T>::~forword_list()
{
	clear();
}
template<class T>
void forword_list<T>::pushback(T &t)
{
	Node<T>*pnew = new Node<T>;
	pnew->t = t;
	pnew->pNext = nullptr;

	if (phead == nullptr)
	{
		this->phead = pnew;
	}
	else
	{
		Node<T>*p = this->phead;
		while (p->pNext != nullptr)
		{
			p = p->pNext;
		}
		p->pNext = pnew;
	}
}
template<class T>
void forword_list<T>::pushback(T &&t)
{
	Node<T>*pnew = new Node<T>;
	pnew->t = t;
	pnew->pNext = nullptr;

	if (phead == nullptr)
	{
		this->phead = pnew;
	}
	else
	{
		Node<T>*p = this->phead;
		while (p->pNext != nullptr)
		{
			p = p->pNext;
		}
		p->pNext = pnew;//尾部插入
	}
}
template<class T>
void forword_list<T>::pushfront(T &t)
{
	Node<T>*pnew = new Node<T>;
	pnew->t = t;
	pnew->pNext = nullptr;

	if (phead == nullptr)
	{
		this->phead = pnew;
	}
	else
	{
		pnew->pNext = phead;
		phead = pnew;//头插法
	}
}
template<class T>
void forword_list<T>::pushfront(T &&t)
{
	Node<T>*pnew = new Node<T>;
	pnew->t = t;
	pnew->pNext = nullptr;

	if (phead == nullptr)
	{
		this->phead = pnew;
	}
	else
	{
		pnew->pNext = phead;
		phead = pnew;//头插法
	}
}
template<class T>
void forword_list<T>::show()
{
	Node<T>*p = this->phead;
	while (p != nullptr)
	{
		cout << p->t << "  ";
		p = p->pNext;
	}
	cout << endl;
}
template<class T>
it<T> forword_list<T>::begin()
{
	return it<T>(this->phead);
}
template<class T>
it<T>  forword_list<T>::end()
{
	Node<T>*p = this->phead;
	while (p != nullptr)
	{
		p = p->pNext;
	}
	return it<T>(p);
}
template<class T>
void forword_list<T>::merge(forword_list<T> & mylist)
{

	Node<T>*p = this->phead;
	while (p->pNext != nullptr)
	{
		p = p->pNext;
	}

	p->pNext = mylist.phead; //链表归并

}
template<class T>
void  forword_list<T>::insert(T t, T newt)
{

	Node<T>*p = find(t);
	if (p != nullptr)
	{
		Node<T> *p1, *p2;
		p1 = this->phead;
		p2 = p1->pNext; 
		//cout << p->t << endl;

		while (p2 != p)
		{
			p1 = p2;
			p2 = p2->pNext;
		}

		Node<T>*px = new Node<T>;
		px->t = newt;
		px->pNext = nullptr;

		p1->pNext = px;
		px->pNext = p2;

	}
}
template<class T>
Node<T> *forword_list<T>::find(T t)
{

	Node<T>*p = this->phead;
	while (p != nullptr)
	{
		if (p->t == t)
		{
			return p;
		}
		p = p->pNext;
	}
	return nullptr;

}



template<class T, class F>
void for_everyone(T begin, T end, F f)//算法
{
	for (auto ib = begin; ib != end; ib++)
	{
		f(*ib);
	}
}
template<class T>
void forword_list<T>::sort()
{
	for (Node<T>*p1 = this->phead; p1 != nullptr; p1 = p1->pNext)
	{
		for (Node<T>*p2 = this->phead; p2 != nullptr; p2 = p2->pNext)
		{
			if (p1->t < p2->t)
			{
				T temp = p2->t;
				p2->t = p1->t;
				p1->t = temp;
			}
		}
	}
}

template<class T>
void forword_list<T>::del(T &t)
{

	Node<T>*p = find(t);
	if (p != nullptr)
	{
		if (p == this->phead)
		{
			this->phead = this->phead->pNext;
		}
		else
		{
			Node<T> *p1, *p2;
			p1 = this->phead;
			p2 = p1->pNext;
			while (p2 != p)
			{
				p1 = p2;
				p2 = p2->pNext;
			}

			p1->pNext = p2->pNext;
			delete p2;

		}

	}

}
template<class T>
void forword_list<T>::del(T &&t)
{

	Node<T>*p = find(t);
	if (p != nullptr)
	{
		if (p == this->phead)
		{
			this->phead = this->phead->pNext;
		}
		else
		{
			Node<T> *p1, *p2;
			p1 = this->phead;
			p2 = p1->pNext;
			while (p2 != p)
			{
				p1 = p2;
				p2 = p2->pNext;
			}

			p1->pNext = p2->pNext;
			delete p2;

		}

	}

}
template<class T>
int  forword_list<T>::getsize()
{
	int i = 0;
	for (Node<T>*p2 = this->phead; p2 != nullptr; p2 = p2->pNext)
	{
		i++;
	}
}
template<class T>
void forword_list<T>::change(T &t, T &newt)
{
	Node<T>*p = find(t);
	if (p != nullptr)
	{
		p->t = newt;
	}
}
template<class T>
void forword_list<T>::change(T &&t, T &&newt)
{
	Node<T>*p = find(t);
	if (p != nullptr)
	{
		p->t = newt;
	}
}
template<class T>
void forword_list<T>::rev()
{
	if (this->phead == nullptr || this->phead->pNext == nullptr)
	{
		return;
	}
	else
	{
		Node<T> *p1, *p2, *p3;
		p1 = this->phead;
		p2 = p1->pNext;
		while (p2!=nullptr)
		{
			p3 = p2->pNext;
			p2->pNext = p1;
			p1 = p2;
			p2 = p3;
		}
		phead->pNext = nullptr;
		phead = p1;
	}
}