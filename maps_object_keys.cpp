/**************************************************************
 * maps_test.cpp
 *
 *  Description: Demonstrating usage of maps with a user defined
 *   object as the map key.
 *
 *
 **************************************************************/



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

	//// operator < needs to be overloaded here as map will use it internally for sorting/comparing the keys.
	//// Maps will always be sorted in smaller to greater value of the key
	bool operator < (const Record &record) const {
		if((this->age < record.age) ||
				((this->age == record.age) && (this->address < record.address))){
			return true;
		}
		else {
			return false;
		}
	}

	//// print needs to be made const because it prints the value of the key which is a const within map implementation
	//// hence print needs to be made a const function so that it cannot modify values of age and address
	//// if we do not use const here, compiler will throw error wherever print is being called
	void print() const {
		cout<<"age : "<<age<<" address : "<<address<<flush;
	}
};

int main()
{

	map<Record,string> myMap;
	myMap[Record(20,"mumbai")] = "jim";
	myMap[Record(50,"london")] = "tom";
	myMap[Record(40,"paris")] = "harry";


	for(map<Record,string>::iterator it=myMap.begin();it!=myMap.end();it++){
		it->first.print();
		cout<<" -> "<<it->second<<endl;
	}

	//// Check if a key exists using find
	if(myMap.find(Record(20,"berlin")) != myMap.end()){
		cout<<"key exists"<<endl;
	}
	else{
		cout<<"key not found"<<endl;
	}

	return 0;
}

