/******************************************************************************

list_test.cpp
Description: Demonstrate usage of list using a menu based application 
where a user can perform the following actions:
    push_back:  adding names to the tail of the list
    push_front:  adding names to the head of the list
    insert:  adding a name to the nth index in the list
    erase:  delete a name from the list

*******************************************************************************/

#include <iostream>
#include <list>

using namespace std;

class Menu
{
    private:
    int op;
    
    public:
    void displayMenu(){
        cout<<"############################"<<endl;
        cout<<"1. push_back"<<endl;
        cout<<"2. push_front"<<endl;
        cout<<"3. insert"<<endl;
        cout<<"4. erase"<<endl;
        cout<<"5. display"<<endl;
        cout<<"6. exit"<<endl;
        cin>>op;
        cout<<endl;
        cout<<"You chose option "<<op<<endl;
    }
    
    int getOption(){
        return op;
    }
};

class List{
    private:
    list<string> myList;
    
    public:
    void pushback(string name){
        myList.push_back(name);
    }
    
    void pushfront(string name){
        myList.push_front(name);
    }
    
    void insert(string name,int index){
        int i=0;
        list<string>::iterator it = myList.begin();
        while(i<index-1){
            it++;
            if(it == myList.end()){
                break;
            }
            i++;
        }
        if(it != myList.end()){
            myList.insert(it,name);
        }
    }
    
    void erase(int index){
        int i=0;
        list<string>::iterator it = myList.begin();
        while(i<index-1){
            it++;
            if(it == myList.end()){
                break;
            }
            i++;
        }
        if(it != myList.end()){
            myList.erase(it);
        }        
    }
    
    void display(){
        list<string>::iterator it = myList.begin();
        for(;it!=myList.end();it++){
            cout<<*it<<endl;
        }
    }
};

class Task
{
    private:
    Menu menu;
    List listOfNames;
    string name;
    int index;
    bool exitLoop;
    
    public:
    Task():exitLoop(false){ }
    
    void performTask(){
        while(1)
        {
            if(exitLoop) break;
            menu.displayMenu();
            switch(menu.getOption())
            {
                case 1:
                cout<<"Enter name : ";
                cin>>name;
                cout<<endl;
                listOfNames.pushback(name);
                break;
                
                case 2:
                cout<<"Enter name : ";
                cin>>name;
                cout<<endl;
                listOfNames.pushfront(name);
                break;                
                
                case 3:
                cout<<"Enter name : ";
                cin>>name;
                cout<<endl;
                cout<<"Enter index : ";
                cin>>index;
                cout<<endl;
                listOfNames.insert(name,index);
                break;  
                
                case 4:
                cout<<"Enter index : ";
                cin>>index;
                cout<<endl;
                listOfNames.erase(index);
                break;            
                
                case 5:
                listOfNames.display();
                break;
                
                case 6:
                exitLoop = true;
                break;
                
                default:
                cout<<"Invalid option"<<endl;
                break;
            }
        }
    }
};

int main()
{
    Task task1;
    task1.performTask();

    return 0;
}
