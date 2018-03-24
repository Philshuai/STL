#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include"String.h"
#include"String.cpp"

using namespace std;


void main1()
{

	String<char> str1("hello");

	//cout << str1 << endl;
	//String<wchar_t> str2;

	str1.show();

	String<wchar_t> str2(L"hello");
	str2.show();

	cin.get();
}

void main()
{
	String<char> str1("hello");
	String<char> str2("world");

	/*if (str1 > str2)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	}*/


	/*str1 += str2;
	str1.show();
*/
	//cout << str1 << endl;
	//(str1 + str2).show();

	String<char> str3;
	str3 = str1 + str2;
	str3.show();

	cout << **str3 << endl;
	cout << *str3 << endl;

	if (str1 < str2)
	{
	cout << 1 << endl;
	}
	else
	{
	cout << 0 << endl;
	}


	cin.get();
}