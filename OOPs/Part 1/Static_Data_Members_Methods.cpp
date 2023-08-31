#include<bits/stdc++.h>
using namespace std;

class Account{
    private:
        int balance; // instance(object) variable
        static float roi; // static variable or class variable (declare)

    public:
        void setData(int b){
            this->balance = b; // because of "this", it is a instance member function
        }

        static void setroi(float r){ // static method or class method
            roi = r;
            cout<<roi<<endl;
        }
};

float Account:: roi = 3.5; //Default value is 0; (define)

int main(){
    Account a1; //Here a1 object has only balance variable, not the static variable(roi)
    // a1.setroi(5.88); // invoked with object(optional but not recommended)
    Account::setroi(2.56); // invoked without object(recommended)


    Account a2; //Similarly, a2 object has only balance variable, not the static variable(roi)
}

/*
Static Data Member :-
Declared inside the class body
Also known as class member
They must be defined outside the class
Static memeber variable does not belong to any object, but to the whole class.
There will be only copy of static member variable for the whole class.
Any object can use the same copy of static/class variable
They can also be used with class name.

Static Data Members in C++
When a static data member is created, there is only a single copy of the data member which is 
shared between all the objects of the class, if the data members are not static then every object 
has an individual copy of the data member and it is not shared.

Static Methods in C++
When a static method is created, they become independent of any object and class. Static methods 
can only access static data members and static methods. Static methods can only be accessed using 
the scope resolution operator.

*/