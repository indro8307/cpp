/******************************************************************************

lambdas.cpp
Description: Demonstrate usage of lambda expressions in C++ 11/14

*******************************************************************************/
#if 0
#include <iostream>
#include <algorithm>
#include <array>



int main()
{
	//// lambdas are internally treaded as function objects
	// a basic demo of lambda. the '()' at the end is needed to
	// invoke the lambda expression.
	[](){std::cout<<"Hello Lambda !!";}();

	// lambdas can be assigned to a variable of type auto or directly
	// used as a predicate to an std algorithm
	auto func = [](int a,int b){return a>b;};
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	std::sort(std::begin(arr),std::end(arr),func);
	// note the use of lambda expressions in sort and for_each
	std::for_each(std::begin(arr),std::end(arr),[](int a){
		// this prints 10 9 8 7 6 5 4 3 2 1
		std::cout<<a<<" ";
	});

	// C++ 14 also supports this: using auto instead of actual types
	std::sort(std::begin(arr),std::end(arr),[](auto a,auto b){
		return a<b;
	});
	std::for_each(std::begin(arr),std::end(arr),[](auto a){
		// this prints 1 2 3 4 5 6 7 8 9 10
		std::cout<<a<<" ";
	});

	// we can specify return types as below:
	auto func1 = [](int a,int b)->float{
		//this will add two integers and return a float type
		return a+b;
	};
	func1(2,3);

	//Lambdas allow capturing of local variables in the following ways:
	// capturing only dummy by value:
	int dummy = 5;
	int another_dummy = 10;
	auto func2 = [dummy](int a){
		return dummy+a;
	};
	std::cout<<std::endl<<func2(10)<<std::endl;

	//capturing only dummy by reference
	auto func3 = [&dummy](int a){
		//this modifies value of dummy
		dummy=a;
	};
	func3(6);
	std::cout<<dummy<<std::endl;

	// if we capture a local variable by value, the lambdas doesnt
	// allow it to be changed and will throw the below error:
	// "error: assignment of read-only variable 'dummy'"
	// solution is to use 'mutable' with lambda expression.
	// However, the change will not get reflected in the actual variable
	// as it was captured by value.
	auto func4 = [dummy](int a) mutable {
		dummy=a;
	};
	func4(7);
	std::cout<<dummy<<std::endl;  // dummy still prints 6

	//capturing all local variables by value
	auto func5 = [=]() {
		std::cout<<dummy<<std::endl;
	};
	func5();

	//capturing all local variables by reference
	auto func6 = [&](int a) {
		dummy=dummy+a;
	};
	func6(10);
	std::cout<<dummy<<std::endl;  // dummy prints 16

	// capturing all local variables by value, but another_dummy by ref
	auto func7 = [=,&another_dummy](int a) {
		another_dummy=another_dummy+a;
	};
	func7(10);
	std::cout<<another_dummy<<std::endl;  // another_dummy prints 20

	//apturing all local variables by ref, but another_dummy by value
	auto func8 = [&,another_dummy](int a) {
		dummy=dummy+a;
	};
	func8(10);
	std::cout<<dummy<<std::endl;  // dummy prints 26

	// from c++14 onwards, the following is possible
	int x=10;
	// introducing a new variable y and initializing it with an expression y=x+10
	// here y is captured by value. To capture it using reference use:
	//  &y=x+10
	auto func9 = [y=x+10](int a){
		return y+a;
	};
	std::cout<<func9(10)<<std::endl;
	return 0;
}

#endif
