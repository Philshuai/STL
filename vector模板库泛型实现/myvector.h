#pragma once
#include<initializer_list>
#include<iostream>
#include<memory>
using namespace std;

template<class T>
class myvector
{
public:
	myvector();//���캯��
	myvector(int n);
	myvector(initializer_list<T>  my);

	~myvector();//����

	T*begin();//����ָ���һ��Ԫ��
	T*end();//����
	int size();
	int arraysize();
	int memsize();
	void show(); 
	void pushback(T &&data);//��ֵ����
	void pushfront(T &&data);
	void pushback(T &data);  //��ֵ����
	void pushfront(T &data);//���õ�����
	//void pushback(T data);//���������ò��ö��󣬽�Լ�ڴ���Ұ�ȫ
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
	     o << "����" << endl;
		 for (int i = 0; i < myv.realn; i++)
		{
			o << myv.p[i] << "  ";
		}
		o << endl;
		return o;
	}


private:
	T *p;
	int memn;//�ڴ泤��
	int realn;//���鳤��
};

