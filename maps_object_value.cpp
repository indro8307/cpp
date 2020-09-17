/**************************************************************
 * maps_test.cpp
 *
 *  Description: Demonstrating usage of maps with a user defined
 *   object as the map value.
 *
 *
 **************************************************************/

#if 0

#include <iostream>
#include <map>

using namespace std;

class Record
{
private:
	int age;
	string address;

public:
	Record(int a,string add):age(a),address(add){

	}

	Record():age(0),address(""){

	}

	void print(){
		cout<<"age : "<<age<<" address : "<<address<<endl;
	}
};


int main()
{
	map<string,Record> myMap;
	myMap["jim"]=Record(20,"12 church street");
	myMap["joe"]=Record(30,"21 dover lane");
	myMap["sara"]=Record(40,"32 park street");


	//// Adding an entry using make_pair
	myMap.insert(make_pair("tom",Record(50,"2 mayo street")));

	//// Adding an entry using pair
	myMap.insert(pair<string,Record>("harry",Record(45,"1/7 college street")));

	//// Check if a key exists using find
	if(myMap.find("harry") != myMap.end()){
		cout<<"key exists"<<endl;
	}
	else{
		cout<<"key not found"<<endl;
	}

	for(map<string,Record>::iterator it=myMap.begin();it!=myMap.end();it++){
		cout<< it->first <<" -> ";
		it->second.print();
	}

	//// Deleting an entry from the map
	myMap.erase("harry");

	for(map<string,Record>::iterator it=myMap.begin();it!=myMap.end();it++){
		pair<string,Record> myPair = *it;
		cout<<myPair.first<<" :: ";
		myPair.second.print();
	}

	return 0;
}

#endif
