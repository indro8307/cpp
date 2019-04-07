/*
 * set_test.cpp
 *
 *  Description: code snippet to explain the idea of set
 *
 */


#include <iostream>
#include <set>

using namespace std;

int main()
{
	////set is a stl container which has only unique elements in a sorted manner
	set<int> mySet;
	mySet.insert(2);
	mySet.insert(1);
	mySet.insert(5);
	mySet.insert(4);
	mySet.insert(5);   // this element will not be inserted as 5 is already present in the set
	mySet.insert(8);

	for(set<int>::iterator it=mySet.begin();it!=mySet.end();it++){
		cout<<*it<<endl;
	}
	return 0;
}

