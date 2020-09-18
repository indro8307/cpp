/******************************************************************************

sort.cpp
Description: Demonstrate usage of std::sort algorithm in C++
1. By default std::sort sorts in ascending order
2. It also accepts a predicate for customized sorting such as descending order
3. O(NLogN) complexity

*******************************************************************************/

#if 1
#include<iostream>
#include<vector>
#include<array>
#include<algorithm>

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
	//// in order to use this type in stl algorithms, we must overload the
	//// <, >, == operators
	bool operator< (const Employee& e) {
		return m_id < e.m_id;
	}

	bool operator> (const Employee& e) {
		return m_id > e.m_id;
	}

	bool operator== (const Employee& e) {
		return m_id == e.m_id;
	}
};

std::ostream& operator<< (std::ostream& os, const Employee& e)
{
	os<<"id = " <<e.m_id << " name = " << e.m_name ;
	return os;
}

int main()
{
	//// sort can be used with C style arrays as well
	int arr[10] = {4,2,3,6,7,1,9,8,10,5};
    int size = sizeof(arr)/sizeof(arr[0]);
	// By default std::sort sorts in ascending order
	std::sort(arr,arr+size);
	std::for_each(arr,arr+size,[](int a){
		std::cout<<a<<" ";
	});
    std::cout<<std::endl;

	//// Using a predicate to sort vector of ints in descending order
	std::vector<int> vec{42,36,7,19,8,105};
	std::sort(vec.begin(),vec.end(),[](int a, int b){
		return a>b;
	});
	//// using a range based for loop for printing the vector
	for(auto i : vec)
		std::cout<<i<<" ";
	std::cout<<std::endl;

	//// sorting a user defined type
	std::array<Employee,5> emparr {Employee{4,"John"},
		                            Employee{2,"Dave"},
									Employee{5,"han"},
									Employee{1,"lol"},
									Employee{3,"jami"},
	                               };
	std::sort(emparr.begin(),emparr.end());
	for(auto i : emparr)
		std::cout<<i<<std::endl;

	return 0;
}

#endif
