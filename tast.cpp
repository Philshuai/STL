#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include"String.h"
#include"String.cpp"

using namespace std;


//void main1()
//{
//
//	String<char> str1("hello");
//
//	//cout << str1 << endl;
//	//String<wchar_t> str2;
//
//	str1.show();
//
//	String<wchar_t> str2(L"hello");
//	str2.show();
//
//	cin.get();
//}
//
void main2()
{
	String<char> str1("hello");
	String<char> str2("world8848");
	String<char> str3;
	str3 = str1 + str2;

	cout << str3<<endl;
	str3.replacefirst("world", "ganssss");

	cout << str3 << endl;


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

	
	/*str3.show();

	cout << **str3 << endl;
	cout << *str3 << endl;

	if (str1 < str2)
	{
	cout << 1 << endl;
	}
	else
	{
	cout << 0 << endl;
	}*/
	  

	/*str3->show();

	(str3->*3)->show();*/

	//cout << str3 << endl;//流式运算符重载成功

	cin.get();
}





void main()
{
	String<wchar_t> str1(L"hello");
	String<wchar_t> str2(L"world8848");
	String<wchar_t> str3;
	str3 = str1 + str2;

	//wcout << str3 << endl;
	//cout << sizeof(L"hi") << endl;

	//cout << wcslen(L"qwe") << endl;



	str3.show();
	str3.replacefirst(L"world88", L"ga");
	str3.show();

	wcout << str3.getdata() << endl;

	//wcout << str3 << endl;



	cin.get();
}


