#include<bits/stdc++.h>
using namespace std;

class Student{
    private:
        int marks;
    public:
        string name;
        int rollno;

        //parameterised constructor
        Student(int rollno, string name){
            this->rollno = rollno; //"this" keyword refers to current object and store the address of current object.
            this->name = name;
        }

        void display(){
            cout<<this->name<<" "<<this->rollno<<endl;
        }
};

int main(){

    // static allocation
    Student s1(56,"Rahul");
    s1.display();


    // dynamic allocation
    Student *s2 = new Student(78,"Mohit");
    s2->display();

}
/*
Parameterized and Default Constructors in C++ :-
Parameterized constructors are those constructors that take one or more parameters. 
Default constructors are those constructors that take no parameters. 
The main things to note here are that constructors are written in the public section of the class and 
the constructors don’t have a return type. 
*/