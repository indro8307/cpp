
/******************************************************************************

arrays.cpp
Description: Demonstrate usage of std::array container in C++
std::array have the following properties:
1. stored in stack unlike vectors. Hence quicker access
2. Aware of its own size unlike C style arrays
3. Doesn't decompose to pointers upon passing to a function (unlike C style array)
4. Inheritance friendly unlike C style arrays. Refer below link:
      https://isocpp.org/wiki/faq/containers#arrays-are-evil

Following std::array methods are demonstrated
    at() - accesses an element with bound check.
    data() - returns actual pointer to the array elements i.e. &arr[0]
    fill() - fills all elements of array with a certain value
    usage of iterators and for_each with arrays

*******************************************************************************/

#if 0
#include <iostream>
#include <array>
#include <algorithm>


class Employee
{
	int m_id = 0;
	std::string m_name = "";
public:
	Employee(int id,std::string name) : m_id{id}, m_name{name} {}
	Employee() = default;
	~Employee() {}
	friend std::ostream& operator<< (std::ostream& os, const Employee& e);
	void operator() (int id, std::string name)
	{
		m_id = id; m_name = name;
	}

};

std::ostream& operator<< (std::ostream& os, const Employee& e)
{
	os<<"id = " <<e.m_id << " name = " << e.m_name ;
	return os;
}

void func(Employee arr[], int size)
{
	for(int i=0;i<size;++i)
	{
		std::cout<<arr[i]<<std::endl;
	}
}

int main()
{
	std::array<Employee,5> emparr {Employee{1,"John"},
		                            Employee{2,"Dave"},
									Employee{3,"han"},
									Employee{4,"lol"},
									Employee{5,"jami"},
	                               };

	//// unlike C style arrays, array containers do boundary check,
	//// but only if you use at() to access elements
	//// Below code snippet throws out_of_range exception
	//// as there are no elements at index 6
	try{
	std::cout<<emparr.at(6)<<std::endl;
	} catch(std::out_of_range const& e)
	{
		std::cout<<e.what()<<std::endl;
	}

	//// can also be treated as a normal C style array
	func(emparr.data(), emparr.size());

    //// can also change values using at() because at() returns an lvalue, i.e. a reference
	emparr.at(0)(6,"Sam");
	func(emparr.data(), emparr.size());

	//// or u can simply use the C style but this DOES NOT do boundary check !!!!
	emparr[2](7,"Jenny");
	std::cout<<"printing in C style "<<emparr[2]<<std::endl;

	//// fill all elements using some value and use foreach to print
	emparr.fill(Employee(0,""));
	std::for_each(emparr.begin(),emparr.end(),[](Employee& e){
		std::cout<<e<<std::endl;
	});
	return 0;
}

#endif
