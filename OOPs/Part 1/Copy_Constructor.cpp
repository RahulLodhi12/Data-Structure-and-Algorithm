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

        //copy constructor
        Student(Student &temp){// pass by reference for modification and avoid infinte loop
            cout<<"Copy Constructor Called!"<<endl;
            this->rollno = temp.rollno;
            this->name = temp.name;
        }

        void display(){
            cout<<this->name<<" "<<this->rollno<<endl;
        }
};

int main(){

    // static allocation
    Student s1(56,"Rahul");
    s1.display();

    Student s2(s1); //copy constructor 
    s2.display();


    // // dynamic allocation
    // Student *s2 = new Student(78,"Mohit");
    // s2->display();

}
/*
Copy Constructor in C++ :-
A copy constructor is a type of constructor that creates a copy of another object. 
If we want one object to resemble another object we can use a copy constructor. 
If no copy constructor is written in the program compiler will supply its own copy constructor.
*/