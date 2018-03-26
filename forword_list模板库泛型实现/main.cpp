#include<iostream>
#include"forword_list.h"
#include"forword_list.cpp" 
#include"it.h"
using namespace std;






void main1()
{
	forword_list<int>mylist;
	for (int i = 0; i < 10; i++)
	{
		mylist.pushback(i);
	}
	mylist.pushfront(20);

	//for (auto i : mylist)
	//{
	//	cout << i.t << "  ";
	//}
	//cout << endl;
	////mylist.show();
	//for (auto ib = mylist.begin(), ie = mylist.end(); ib != ie; ib++)
	//{
	//	cout << ib->t << endl;
	//}

	/*mylist.show();*/


	for_everyone(mylist.begin(), mylist.end(), [](int num){cout << num << endl; });

	cin.get();
}

void main()
{
	forword_list<int>mylist;
	for (int i = 0; i < 10; i++)
	{
		mylist.pushback(i);
	}

	for (auto i : mylist)
	{
		//cout << typeid(i).name() << endl;
		cout << i << "  ";
	}

	mylist.rev();
	//mylist.del(4);
    // mylist.insert(4, 10);

	// mylist.del(9);

	mylist.change(5, 2000);
	cout << endl;
	mylist.show();
	mylist.sort();


	cout << endl;
	for (auto i : mylist)
	{
		cout << i<< "  "; 
	}
	cout << endl;


	cin.get();
}