#include<bits/stdc++.h>
using namespace std;

class Student{
    private:
        int marks;
    public:
        string name;
        int rollno;

        Student(){ // default constructor
            cout<<"Constructor Called!"<<endl;
        }
};

int main(){

    // static allocation
    Student s1; 
    // During object creation, a s1.Student() is invoked which is in-built(complier), even its not created in class Student,
    //and it is known as constructor or in this case, default constructor.
    // OR in other words, Constructors are automatically invoked whenever an object is created.

    // dynamic allocation
    Student *s2 = new Student();
}
/*
Constructors in C++ :-
A constructor is a special member function with the same name as the class. 
The constructor doesn’t have a return type. 
Constructors are used to initialize the objects of its class. 
Constructors are automatically invoked whenever an object is created.


Important Characteristics of Constructors in C++ :-
A constructor should be declared in the public section of the class
They are automatically invoked whenever the object is created
They cannot return values and do not have return types
It can have default arguments
We cannot refer to their address

*/

