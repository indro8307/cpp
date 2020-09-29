/*
 * rvalue-reference.cpp
 *
 *  Created on: 28-Sep-2020
 *      Author: indranil
 *
 *  Description: Demonstrate the concept of r-value reference and the
 *  difference between lvalue, rvalue, lvalue reference and rvalue reference
 *
 */

#if 1
#include <iostream>

int func_return_rvalue()
{
	int temp = 2;
	return temp;
}

int& func_return_lvalue(int &temp)
{
	temp = 2;
	return temp;
}

int func_accepting_rvalue_ref(int &&val)
{
	std::cout<<"Inside func_accepting_rvalue_ref"<<std::endl;
	return 3+val;
}

int main()
{
	// lvalue is anything that has a name or location for eg:
	int val = 10;  // here 'val' is an l value as it has a name and an address
	               // and 10 is the rvalue. You can assign values to lvalue but
	// not to an rvalue.

	// an lvalue reference can only be bound to a lvalue as below:
	int &this_is_a_lvalue_ref = val;
	std::cout<<this_is_a_lvalue_ref<<std::endl;
	// int &this_is_a_lvalue_ref = 20 -> this will not work

	// below function returns an rvalue.
	int out = func_return_rvalue();
	std::cout<<out<<std::endl;
		// int &this_is_a_lvalue_ref = 20 -> this will not work

	//below function returns an lvalue and hence can be used to assign a value to eg.
	func_return_lvalue(out) = 4;
	// NOTE: func_return_lvalue(3); will throw error as the function does not accept
	// rvalue reference. To fix this error use the below signature
	//  int& func_return_lvalue(const int &temp)

	// C++11 introduced rvalue reference for supporting move semantics
	// an rvalue reference used to represent a temporary. It always binds
	// to a rvalue i.e. a temporary object. It is represented by &&
	int &&this_is_a_rvalue_ref = 20;
	int &&catching_a_temporary_return_value = func_return_rvalue();
	std::cout<<this_is_a_rvalue_ref<<" "<<catching_a_temporary_return_value<<std::endl;

	int &&ret_val = func_accepting_rvalue_ref(10);
	std::cout<<"ret_val = "<<ret_val<<std::endl;

	return 0;

}

#endif


