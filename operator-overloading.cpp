/*
 * operator-overloading.cpp
 *
 *  operator-overloading.cpp
 *  description:  demonstratig operator overloading with the following examples:
 *      - overloading assignment operator
 *      - overloading << operator
 *      - overloading + operator
 *      - overloading == operator
 *      - overloading [] operator
 *
 */
#if 0
#include <iostream>

using namespace std;

class Record {
	string name;
	int age;

public:
	Record() : name(""), age(0) { }
	Record(string n,int a) : name(n), age(a) { }

	//// Copy constructor
	Record(const Record & r) {
		cout<<"Inside Copy Constructor"<<endl;
		name = r.name;
		age = r.age;
	}

	//// overloaded assignment operator
	const Record & operator=(const Record & rec) {
		cout<<"Inside assignment operator overloader"<<endl;
		name = rec.name;
		age = rec.age+10;
		return *this;
	}

	//// overloaded + operator
	const Record & operator+(const Record & rec) {
		cout<<"Inside overloaded + operator"<<endl;
		name = name + rec.name;  // this is only for demo, does'nt make sense in real life
		age = age + rec.age;
		return *this;   // returning a reference to the current object
	}

	//// overloaded == operator
	bool operator==(const Record & rec) const {
		if((name==rec.name) && (age==rec.age)) {
			return true;
		}
		else
			return false;
	}

	//// Trying to overload [] operator
	const Record & operator[](const string str) {
		name = str;
		return *this;
	}

	friend ostream & operator<<(ostream & out, Record & rec);

};

//// overloaded << operator. This is not kept as a
//// member function because the first argument should
//// be ostream. in a member function, 'this' is the first argument
ostream & operator<<(ostream & out, Record & rec) {
	out<<rec.name<<" : "<<rec.age;
	return out;
}

int main() {
	Record record1;
	Record record2("john",30);
	Record record3 = record2;
	Record record4;
    record1 = record4 = record3;

    Record record5(" doe",20);
    record2 = record2 + record5;

    Record record6 = record5;
    if(record6 == record5) {
    	cout<<"record5 and record6 are equal"<<endl;
    }

    Record record7;
    record7["hello"];
    cout<<record1<<endl<<record2<<endl<<record3<<endl<<record4<<endl<<record5
    		<<endl<<record6<<endl<<record7;

    return 0;
}

#endif
