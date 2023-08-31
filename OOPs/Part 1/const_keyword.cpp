#include<bits/stdc++.h>
using namespace std;

class Test{
    private:
        const int n;
    public:
        Test():n(10){ // default constructor
            cout<<"Value of n: "<<n<<endl;
        }

};

int main(){
    Test t1;
}

/*
Constant Data Members of class :-
Data members are like the variable that is declared inside a class, but once the data member is initialized, 
it never changes, not even in the constructor or destructor. 
The constant data member is initialized using the const keyword before the data type inside the class.
They are not initialized during declaration.
Their initialization occurs in constructor.

Constant Class Objects :-
When we create an object using the const keyword, the value of data members can never change 
till the life of the object in a program. The const objects are also known as the read-only objects.
Syntax: const class_name obj_name;

Const Member function of class
A const is a constant member function of a class that never changes any class data members, and it also does not call any non-const function.
It is also known as the read-only function.
We can create a constant member function of a class by adding the const keyword after the name of the member function.
Syntax:
    return_type mem_fun() const{  
      // code like assign value -> which don't change because of "const" keyword.
    }   
*/