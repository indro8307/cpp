/*
 * multimap_test.cpp
 *
 * Description:  Demonstrating usage of multimaps and how to
 *      access elements with same keys
 *
 */

#if 0
#include <iostream>
#include <map>

using namespace std;

int main()
{
	multimap<int,string> myMap;
	myMap.insert(make_pair(1,"tom"));
	myMap.insert(make_pair(1,"john"));
	myMap.insert(make_pair(2,"bob"));
	myMap.insert(make_pair(3,"harry"));
	myMap.insert(make_pair(3,"tony"));

	for(multimap<int,string>::iterator it=myMap.begin();it!=myMap.end();it++){
		cout<<it->first<<" : "<<it->second<<endl;
	}

	cout<<endl;
	//// equal_range finds a sequence matching the given key
	pair< multimap<int,string>::iterator, multimap<int,string>::iterator> its = myMap.equal_range(1);
	for(multimap<int,string>::iterator it=its.first;it!=its.second;it++){
		cout<<it->first<<" : "<<it->second<<endl;
	}
    return 0;
}

#endif
