
#include<iostream>
#include"myvector.h"
#include"myvector.cpp"
using namespace std;


void main()
{
	myvector<double> myv{ 1.1, 2.2, 3.3 };

	/*myv.show();

	myv.pushback(4.4);
	myv.pushfront(19.2);
	myv.del(3.3);*/
	myv.insert(2.2, 2.8);

	//myv.show();

	cout << myv;//重载流式运算符

	/*for (auto i : myv)
	{
		cout << i << endl;
	} 
*/
	/*for (auto ib = myv.begin(), ie = myv.end(); ib != ie; ib++)
	{
		cout << *ib << endl;
	}*/
	cin.get();
}