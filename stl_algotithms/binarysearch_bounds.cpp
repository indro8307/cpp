/******************************************************************************

binarysearch_bounds.cpp
Description: Demonstrate usage of std::binary_search, upper_bound
and lower_bound algorithms in C++
Finds the element in the given range of numbers.

std::binary_search:
- All elements should be sorted
- Complexity of search is O(Log N)
- returns true if element is present, false otherwise
- may also accept a binary predicate as the third argument

std::upper_bound:
- Returns an iterator pointing to the first element in the range [first, last)
that is greater than value, or last if no such element is found.
- All elements should be sorted
- Complexity is O(Log last-first)

std::lower_bound:
- Returns an iterator pointing to the first element in the range [first, last)
that is not less than (i.e. greater or equal to) value,or last if no such
element is found.
- All elements should be sorted
- Complexity is O(Log last-first)

*******************************************************************************/

#if 1
#include <iostream>
#include <algorithm>
#include <vector>


int main()
{
	std::vector<int> vec{4,2,7,3,6,7,1,9,7,8,10,5};
	//// First sort the vector O(NLog N)
	std::sort(vec.begin(),vec.end());
	for(auto i : vec)
	{
		std::cout<<i<<" ";  // O/P 1 2 3 4 5 6 7 7 7 8 9 10
	}
	std::cout<<std::endl;

	//binary_search() - O(Log N)
	bool present = std::binary_search(vec.begin(),vec.end(),7);
	if(present)
		std::cout<<"7 is present"<<std::endl;

	//upper_bound
	auto it_upper = std::upper_bound(vec.begin(),vec.end(),7);
	std::cout<<"upper bound of 7 is "<<*it_upper<<" at index "<<it_upper-vec.begin()<<std::endl;

	//lower_bound
	auto it_lower = std::lower_bound(vec.begin(),vec.end(),7);
	std::cout<<"lower bound of 7 is "<<*it_lower<<" at index "<<it_lower-vec.begin()<<std::endl;

	std::cout<<"Therefore, number of occurrences of 7 is "<<it_upper-it_lower<<std::endl;

	return 0;
}

#endif
