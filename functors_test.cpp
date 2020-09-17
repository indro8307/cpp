/*
 * functors_test.cpp
 *
 *  Description: Demonstrating the usage of functors.
 *      
 */
#if 0
#include <iostream>
#include <vector>

using namespace std;

struct Adder
{
	int operator()(int &sum, int &element){     // This is a Functor
		return sum+element;
	}
};

int accumulate_impl(vector<int>::iterator begin, vector<int>::iterator end, Adder adder) {
	int sum = 0;
	for(vector<int>::iterator it = begin;it!=end;it++) {
		sum = adder(sum,*it);
	}
	return sum;
}

int main()
{
	vector<int> numbers = {1,2,3,4,5};   // It is possible to initialize vectors this way in C++ 11
	Adder adder;
	//vector<int>::iterator begin = numbers.begin()
	int sum = accumulate_impl(numbers.begin(),numbers.end(),adder);
	cout<<sum;
	return 0;
}

#endif
