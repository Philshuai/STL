#pragma once
#include"Node.h"
#include"it.h"
#include<iostream>
using namespace std;
template<class T>
class forword_list
{
private:
	Node<T> *phead;//ͷ�ڵ�
public:
	forword_list();
	void pushback(T &t);
	void pushback(T &&t);
	void pushfront(T &t); 
	void pushfront(T &&t);
	void show();

	it<T> begin();
	it<T> end();
	void merge(forword_list<T> & mylist);
	void insert(T t, T newt);
	Node<T> *find(T t);

	void clear();


	void sort();//����


	void del(T &t);//ɾ��
	void del(T &&t);//ɾ��
	int getsize();//��ȡ�����С
	void change(T &t, T &newt);
	void change(T &&t, T &&newt);
	void rev();//����ת

	~forword_list();

};

