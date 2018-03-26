#pragma once
#include"Node.h"
#include"it.h"
#include<iostream>
using namespace std;
template<class T>
class forword_list
{
private:
	Node<T> *phead;//头节点
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


	void sort();//排序


	void del(T &t);//删除
	void del(T &&t);//删除
	int getsize();//获取链表大小
	void change(T &t, T &newt);
	void change(T &&t, T &&newt);
	void rev();//链表反转

	~forword_list();

};

