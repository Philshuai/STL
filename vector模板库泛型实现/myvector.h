#pragma once
#include<initializer_list>
#include<iostream>
#include<memory>
using namespace std;

template<class T>
class myvector
{
public:
	myvector();//构造函数
	myvector(int n);
	myvector(initializer_list<T>  my);

	~myvector();//析构

	T*begin();//返回指向第一个元素
	T*end();//结束
	int size();
	int arraysize();
	int memsize();
	void show(); 
	void pushback(T &&data);//右值引用
	void pushfront(T &&data);
	void pushback(T &data);  //左值引用
	void pushfront(T &data);//引用的重载
	//void pushback(T data);//参数用引用不用对象，节约内存而且安全
	//void pushfront(T data);
	T operator [](int i) const ;
	T & operator [](int i);

	T *find(T &&data);
	T *find(T &data);

	void change(T *pos, T & t);
	void change(T *pos, T && t);

	void del(T && t);
	void del(T & t);

	void insert(T & t,T & newt);
	void insert(T && t, T && newt);


	friend ostream &operator<<(ostream &o,const  myvector &myv)
	{
	     o << "数组" << endl;
		 for (int i = 0; i < myv.realn; i++)
		{
			o << myv.p[i] << "  ";
		}
		o << endl;
		return o;
	}


private:
	T *p;
	int memn;//内存长度
	int realn;//数组长度
};

