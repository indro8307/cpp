/**************************************************************
 * maps_test.cpp
 *
 *  Description: Demonstrating usage of maps.
 *
 *
 **************************************************************/

#if 0
#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<string,int> myMap;
	myMap["jim"]=1;
	myMap["joe"]=2;
	myMap["sara"]=3;

	//// The below line will add an entry with key "tim" !!!
	//// And all the entries will be sorted...
	cout<<myMap["tim"]<<endl;

	//// Adding an entry using make_pair
	myMap.insert(make_pair("tom",5));

	//// Adding an entry using pair
	myMap.insert(pair<string,int>("harry",5));

	//// Check if a key exists using find
	if(myMap.find("leo") != myMap.end()){
		cout<<"key exists"<<endl;
	}
	else{
		cout<<"key not found"<<endl;
	}

	for(map<string,int>::iterator it=myMap.begin();it!=myMap.end();it++){
		cout<<it->first<<" : "<<it->second<<endl;
	}

	//// Deleting an entry from the map
	myMap.erase("harry");

	for(map<string,int>::iterator it=myMap.begin();it!=myMap.end();it++){
		pair<string,int> myPair = *it;
		cout<<myPair.first<<" :: "<<myPair.second<<endl;
	}

	return 0;
}

#endif
