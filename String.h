#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<iostream>


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
	/*T *operator ->(int i);
	T *operator ->*(int i);*/

	//void replacefirst(const String &oldstr, const String &newstr);
	//void replaceall(const String &oldstr, const String &newstr);

	//void findfirst(const String &oldstr, const String &newstr);
	//void findall(const String &oldstr, const String &newstr);


	T operator[](int id);

	void show();

	T *getdata();

	//template<class T>
	//friend ostream & operator <<(ostream &o, const  String<T> &str)//÷ÿ‘ÿ¡˜
	//{
	//	o << str.pstart;
	//	return o;
	//}

private:
	T *pstart;
	int length;
};

