/******************************************************************************

find.cpp
Description: Demonstrate usage of std::find algorithm in C++
Finds the element in the given range of numbers.
find_if searches for an element for which predicate p returns true.
find_if_not searches for an element for which predicate q returns false.

Return Value
returns an iterator to the first element in the range [first,last]
that compares equal to val. If no such element is found, the function returns last.

Complexity
At most last - first applications of the predicate - O(N)

*******************************************************************************/

#if 0
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	//// plain and simple std::find using vector
	std::vector<int> vec{1,2,3,6,4,5,9,8,7};
	auto it = std::find(vec.begin(), vec.end(), 7);
	std::cout<<*it<< " found at "<<it-vec.begin()<<std::endl;

	//// some containers have their own implementation of find
	//// as in std::string. Below code snippet prints substrings based on a delimiter
	unsigned int pos = 0,pos1 = 0;
	std::string str = "cat,dog,mouse,man";
	pos = str.find("," , pos);

	while(pos != std::string::npos)
	{
		std::cout<<str.substr(pos1,pos-pos1)<<std::endl;
		pos1 = ++pos;
		pos = str.find("," , pos);
	}
    if(pos1<str.size())
    	std::cout<<str.substr(pos1,str.size()-pos1)<<std::endl;

    //// demonstrating find_if
    std::cout<<std::endl;
	std::vector<int> vec1{1,2,3,6,4,5,9,8,7};
	auto func = [](int a){ return a%3==0 ;};
	auto it1 = std::find_if(vec1.begin(), vec1.end(), func);
	std::cout<<*it1<< " found at "<< it1-vec1.begin() <<" index"<<std::endl;
	it1 = std::find_if(++it1, vec1.end(), func);
	std::cout<<*it1<< " found at "<< it1-vec1.begin() <<" index"<<std::endl;

    return 0;
}

#endif


