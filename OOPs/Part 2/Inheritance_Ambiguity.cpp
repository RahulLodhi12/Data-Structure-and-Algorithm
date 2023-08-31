/*
**Inheritance Ambiguity**
In multiple inheritances, when one class is derived from two or more base classes then 
there may be a possibility that the base classes have functions with the same name, 
and the derived class may not have functions with that name as those of its base classes. 
If the derived class object needs to access one of the similarly named member functions of the 
base classes then it results in ambiguity because the compiler gets confused about 
which base’s class member function should be called.
*/

/*
Solution to  Ambiguity:-
To solve this ambiguity scope resolution operator is used denoted by "::"
Syntax:
ObjectName.ClassName::FunctionName();
*/

#include<bits/stdc++.h>
using namespace std;

class A{
    public:
        
        void abc(){
            cout<<"This is Class A"<<endl;
        }
};

class B{
    public:

        void abc(){
            cout<<"This is Class B"<<endl;
        }

};

class C:  public A, public B{
    public:
        void func(){
            cout<<"Class C"<<endl;
        }
};

int main(){

    C obj;
    // obj.abc(); // error: "abc" is ambiguous

    obj.A::abc();
    obj.B::abc();

}