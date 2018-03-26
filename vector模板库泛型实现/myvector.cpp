#include "myvector.h"

template<class T>
myvector<T>::myvector() :p(nullptr), memn(0), realn(n)
{
}

template<class T>
myvector<T>::~myvector()
{
	if (p != nullptr)
	{
		delete[] this->p;
	}
}


template<class T>
myvector<T>::myvector(int n)
{
	this->memn = this->realn = n;
	this->p = new T[n];
	memset(this->p, 0, sizeof(T)*n);
}

template<class T>
myvector<T>::myvector(initializer_list<T>my)
{
	//cout << "1234" << endl;
	this->realn = this->memn = my.size();
	cout << this->realn << endl;

	this->p = new T[my.size()];
	int id = 0;
	for (auto i : my)//初始化
	{
		this->p[id++] = i;
	}

}

template<class T>
void myvector<T>::show()
{
	cout << "数组" << endl;
	for (int i = 0; i < this->realn; i++)
	{
		cout << this->p[i] << "  ";
	}
	cout << endl;
}
template<class T>
T* myvector<T>::begin()
{
	return this->p;

}
template<class T>
T* myvector<T>::end()
{
	return this->p + this->realn;

}
template<class T>
int myvector<T>::size()
{
	return this->realn;
}
template<class T>
int myvector<T>::memsize()
{
	return this->memn;
}
template<class T>
void myvector<T>::pushback(T &&data)
{
	if (this->p == nullptr || this->realn == 0)
	{
		if (this->memn == 0)
		{
			p = new T;
			*p = data;
			realn = 1;
			memn = 1;
		}
		else
		{
			*p = data;
			realn = 1;
		}
	}
	else
	{
		T *ptemp = new T[this->realn + 1];//尾部插入
		memcpy(ptemp, this->p, sizeof(T)*(this->realn));
		*(ptemp + realn) = data;
		delete[] this->p;
		this->p = ptemp;
		realn += 1;
		memn += realn;
	}
}
template<class T>
void myvector<T>::pushfront(T &&data)
{
	if (this->p == nullptr || this->realn == 0)
	{
		if (this->memn == 0)
		{
			p = new T;
			*p = data;
			realn = 1;
			memn = 1;
		}
		else
		{

			*p = data;
			realn = 1;
		}
	}
	else
	{
		T *ptemp = new T[this->realn + 1];//头部插入
		memcpy(ptemp + 1, this->p, sizeof(T)*(this->realn));
		*(ptemp) = data;
		delete[] this->p;
		this->p = ptemp;
		realn += 1;
		memn += realn;
	}
}

template<class T>
void myvector<T>::pushback(T &data)
{
	if (this->p == nullptr || this->realn == 0)
	{
		if (this->memn == 0)
		{
			p = new T;
			*p = data;
			realn = 1;
			memn = 1;
		}
		else
		{
			*p = data;
			realn = 1;
		}
	}
	else
	{
		T *ptemp = new T[this->realn + 1];//尾部插入
		memcpy(ptemp, this->p, sizeof(T)*(this->realn));
		*(ptemp + realn) = data;
		delete[] this->p;
		this->p = ptemp;
		realn += 1;
		memn += realn;
	}
}
template<class T>
void myvector<T>::pushfront(T &data)
{
	if (this->p == nullptr || this->realn == 0)
	{
		if (this->memn == 0)
		{
			p = new T;
			*p = data;
			realn = 1;
			memn = 1;
		}
		else
		{

			*p = data;
			realn = 1;
		}
	}
	else
	{
		T *ptemp = new T[this->realn + 1];//头部插入
		memcpy(ptemp + 1, this->p, sizeof(T)*(this->realn));
		*(ptemp) = data;
		delete[] this->p;
		this->p = ptemp;
		realn += 1;
		memn += realn;
	}
}

template<class T>
T myvector<T>::operator [](int i) const
{
	if (i < 0 || i >= this->realn)
	{
		throw 1;
	}
	return this->p[i];
}
template<class T>
T & myvector<T>::operator [](int i)
{
	if (i < 0 || i >= this->realn)
	{
		throw 2;
	}
	return this->p[i];
}


template<class T>
T *myvector<T>::find(T &&data)
{
	for (auto ib = this->begin(), ie = this->end(); ib != ie; ib++)
	{
		if ((*ib) == data)
		{
			return ib;
		}
	}
	return nullptr;
}
template<class T>
T *myvector<T>::find(T &data)
{
	for (auto ib = this->begin(), ie = this->end(); ib != ie; ib++)
	{
		if ((*ib) == data)
		{
			return ib;
		}
	}
	return nullptr;
}
template<class T>
void myvector<T>::change(T *pos, T & t)
{
	if (pos != nullptr)
	{
		*pos = t;
	}
}
template<class T>
void myvector<T>::change(T *pos, T && t)
{
	if (pos != nullptr)
	{
		*pos = t;
	}
}

template<class T>
void myvector<T>::del(T && t)
{
	int pos = -1;
	for (int i = 0; i < this->realn; i++)
	{
		if (t == *(this->p + i))
		{
			pos = i;
			break;
		}
	}
	if (pos != -1)
	{
		//cout << this->realn << "  " << pos << endl;
		if (pos == this->realn-1)
		{
			this->realn -= 1;
		}
		else
		{
			for (int i = pos; i < this->realn; i++)
			{
				this->p[i] = this->p[i + 1];
			}
			this->realn -= 1;
		}
	}
}
template<class T>
void myvector<T>::del(T & t)
{
	int pos = -1;
	for (int i = 0; i < this->realn; i++)
	{
		if (t == *(this->p + i))
		{
			pos = i;
			break;
		}
	}
	if (pos != -1)
	{
		if (pos == this->realn-1)
		{
			this->realn -= 1;
		}
		else
		{
			for (int i = pos; i < this->realn; i++)
			{
				this->p[i] = this->p[i + 1];
			}
			this->realn -= 1;
		}
	}
}

template<class T>
void myvector<T>::insert(T & t, T & newt)
{
	if (this->realn == this->memn)
	{
		int pos = -1;
		for (int i = 0; i < this->realn; i++)
		{
			if (t == *(this->p + i))
			{
				pos = i;
				break;
			}
		}
		if (pos != -1)
		{
			T *ptemp = new T[this->realn + 1];
			memcpy(ptemp, this->p, sizeof(T)*memn);
			delete[] this->p;
			this->p = ptemp;
			this->realn += 1;
			this->memn += 1;
			//拷贝
			for (int i = realn - 2; i >= pos; i--)
			{
				this->p[i + 1] = this->p[i];

			}
			this->p[pos] = newt;
		}
	}
	else
	{
		int pos = -1;
		for (int i = 0; i < this->realn; i++)
		{
			if (t == *(this->p + i))
			{
				pos = i;
				break;
			}
		}
		if (pos != -1)
		{
			
			for (int i = realn - 1; i >= pos; i--)
			{
				this->p[i + 1] = this->p[i];

			}
			this->p[pos] = newt;
			this->realn += 1;

		}
	}


}
template<class T>
void myvector<T>::insert(T && t, T && newt)
{

	if (this->realn == this->memn)
	{
		int pos = -1;
		for (int i = 0; i < this->realn; i++)
		{
			if (t == *(this->p + i))
			{
				pos = i;
				break;
			}
		}
		if (pos != -1)
		{
			T *ptemp = new T[this->realn + 1];
			memcpy(ptemp, this->p, sizeof(T)*memn);
			delete[] this->p;
			this->p = ptemp;
			this->realn += 1;
			this->memn += 1;
			//拷贝
			for (int i = realn - 2; i >= pos; i--)
			{
				this->p[i + 1] = this->p[i];

			}
			this->p[pos] = newt;
		}
	}
	else
	{
		int pos = -1;
		for (int i = 0; i < this->realn; i++)
		{
			if (t == *(this->p + i))
			{
				pos = i;
				break;
			}
		}
		if (pos != -1)
		{

			for (int i = realn - 1; i >= pos; i--)
			{
				this->p[i + 1] = this->p[i];

			}
			this->p[pos] = newt;
			this->realn += 1;

		}
	}
}