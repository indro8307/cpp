/******************************************************************************

vector_memory

Description: understanding internal memory allocation
scheme in vectors using size, capacity, reserve, clear
methods.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> numbers(30,0);  // creating a vector of size 30 and initializing it to zeros
    cout<<"Size of numbers = "<<numbers.size()<<endl;
    cout<<"Capacity of numbers = "<<numbers.capacity()<<endl;
    int cap = numbers.capacity();
    for(int i=0;i<1000;i++)
    {
        if(cap != numbers.capacity())
        {
            cap = numbers.capacity();
            cout<<"Size of numbers = "<<numbers.size()<<endl;   // size() returns the number of elements in the vector
            cout<<"Capacity of numbers = "<<cap<<endl;  // capacity() returns the total allocated memory
        }
        numbers.push_back(i);
    }
    
    // clear will remove all the elements from the vector but 
    // the capacity of the vector will remain unchanged
    numbers.clear();
    cout<<"Size of numbers after clear = "<<numbers.size()<<endl;
    cout<<"Capacity of numbers after clear= "<<numbers.capacity()<<endl;
    
    // reserve will increase the capacity of the vector without changing the size
    numbers.reserve(10000);
    cout<<"Size of numbers after reserve = "<<numbers.size()<<endl;
    cout<<"Capacity of numbers after reserve= "<<numbers.capacity()<<endl;

    return 0;
}
