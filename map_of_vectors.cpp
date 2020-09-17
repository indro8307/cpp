/**************************************************************
 * maps_test.cpp
 *
 *  Description: Demonstrating a map of vectors
 *   and Ways to add and delete elements
 *
 *
 **************************************************************/

#if 0

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Record
{
private:
	int age;
	string name;

public:
	Record(int a,string add):age(a),name(add){

	}

	Record():age(0),name(""){

	}

	//// operator < needs to be overloaded here as map will use it internally for sorting/comparing the keys.
	//// Maps will always be sorted in smaller to greater value of the key
	bool operator < (const Record &record) const {
		if((this->age < record.age) ||
				((this->age == record.age) && (this->name < record.name))){
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
		cout<<"age : "<<age<<" name : "<<name<<flush;
	}
};

int main()
{
	map<int, vector<Record> > mapOfVectors;
	vector<Record> record1,record2;
	record1.push_back(Record(20,"john"));
	record1.push_back(Record(30,"paul"));
	record2.push_back(Record(40,"george"));
	record2.push_back(Record(50,"ringo"));

	mapOfVectors.insert(make_pair(1,record1));
	mapOfVectors.insert(make_pair(2,record2));

	for(map<int,vector<Record>>::iterator it=mapOfVectors.begin();it!=mapOfVectors.end();it++){
		cout<<it->first<<": ";
		vector<Record> tempVec = it->second;
		for(vector<Record>::iterator itr=tempVec.begin();itr!=tempVec.end();itr++){
			itr->print();
			cout<<" ; ";
		}
		cout<<endl;
	}

	mapOfVectors[1].push_back(Record(45,"bob"));
	mapOfVectors[1].push_back(Record(45,"joan"));

	cout<<endl;

	for(map<int,vector<Record>>::iterator it=mapOfVectors.begin();it!=mapOfVectors.end();it++){
		cout<<it->first<<": ";
		vector<Record> tempVec = it->second;
		for(vector<Record>::iterator itr=tempVec.begin();itr!=tempVec.end();itr++){
			itr->print();
			cout<<" ; ";
		}
		cout<<endl;
	}

	mapOfVectors[1].erase(mapOfVectors[1].begin() + 1);
	mapOfVectors[2].clear();

	//// Deleting a node in the map based on key value
	mapOfVectors.erase(2);

	cout<<endl;

	for(map<int,vector<Record>>::iterator it=mapOfVectors.begin();it!=mapOfVectors.end();it++){
		cout<<it->first<<": ";
		vector<Record> tempVec = it->second;
		for(vector<Record>::iterator itr=tempVec.begin();itr!=tempVec.end();itr++){
			itr->print();
			cout<<" ; ";
		}
		cout<<endl;
	}

	return 0;
}

#endif
