/******************************************************************************

test_vector

Description: understanding vector and push_back function

*******************************************************************************/
#if 0
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //// myListOfNames is a vector whose size will increase at runtime.
    vector<string> myListOfNames;
    myListOfNames.push_back("John");
    myListOfNames.push_back("Paul");
    myListOfNames.push_back("George");
    myListOfNames.push_back("Ringo");
    cout<<"Size of myListOfNames = "<<myListOfNames.size()<<endl;
    vector<string>::iterator it;
    for(it = myListOfNames.begin();it != myListOfNames.end();it++)
    {
        cout<<*it<<endl;
    }
    
    
    //// myListOfNames2: initializing it to size 3. 
    //// calling push_back on myListOfNames2 will increase the size
    vector<string> myListOfNames2(3);
    myListOfNames2.push_back("Peter");
    myListOfNames2.push_back("Paul");
    myListOfNames2.push_back("Mary");
    cout<<"Size of myListOfNames2 = "<<myListOfNames2.size()<<endl;         //// size=6
    //// First three vector elements are empty and will print nothing
    for(it = myListOfNames2.begin();it != myListOfNames2.end();it++)
    {
        cout<<*it<<endl;
    }
    myListOfNames2[0] = "somebody";
    myListOfNames2[1] = "anybody";
    myListOfNames2[2] = "everybody";
    for(it = myListOfNames2.begin();it != myListOfNames2.end();it++)
    {
        cout<<*it<<endl;
    }
    
    return 0;
}
#endif
