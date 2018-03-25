#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<iostream>
#include<functional>
#include<memory>

using namespace std;

class erroroutofrange
{

};

template<class T>//char wchar_t
class String
{
public:
	String();
	~String();
	String(const T *p);
	String(const String &p);

	void operator =(const String &str);
	void operator +=(const String &str);
	String<T> operator +(String &str);
	bool operator ==(const String &str);
	bool operator <=(const String &str);
	bool operator >=(const String &str);
	bool operator <(const String &str);
	bool operator >(const String &str);
	bool operator !=(const String &str);
	T *operator *();


	String *operator ->();
	String *operator ->*(int i);


	void replacefirst(const String &oldstr, const String &newstr);
	//void replaceall(const String &oldstr, const String &newstr);

	//void findfirst(const String &oldstr, const String &newstr);
	//void findall(const String &oldstr, const String &newstr);

	//void insertfirst(const String &oldstr, const String &newstr);
	//void insertall(const String &oldstr, const String &newstr);

	//void deletefirst(const String &oldstr, const String &newstr);
	//void deleteall(const String &oldstr, const String &newstr);



	T operator[](int id)const;
	T & operator[](int id);
	void show();

	T *getdata();
	int getlength();//��ȡ����


	//������������ر��������ģ���ڲ�
	friend ostream & operator <<(ostream &o, const  String &str)//������
	{
		o << str.pstart;
		return o;
	}
	friend istream & operator >> (ostream &i, const  String &str)//������
	{
		i << str.pstart;
		return i; 
	}


private:
	T *pstart;
	int length;

	function<void(void) >fun = [=](){cout << pstart << endl; };//��=Ĭ���Դ�thisָ��

};

