#include<bits/stdc++.h>
using namespace std;

class num{
    public:
        num(){ //constructor
            cout<<"Constructor is called"<<endl;
        }

        ~num(){ //destructor
            cout<<"Destructor is called"<<endl;
        }
};

int main(){
    //static allocation -> Destructor called automatically
    num n1;

    //dynamic allocation -> Destructor called mannually
    num *n2 = new num();
    delete n2; //here it called destructor
}
/*
Destructor in C++ :-
A destructor is a type of function which is called when the object is destroyed. 
Destructor never takes an argument nor does it return any value.
*/

