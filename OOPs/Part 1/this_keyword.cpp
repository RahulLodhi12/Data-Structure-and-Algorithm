#include<bits/stdc++.h>
using namespace std;

class Student{
    private:
        int marks;
    public:
        string name;
        int rollno;

        //parameterised constructor
        Student(int rollno){
            this->rollno = rollno; //"this" keyword refers to current object and store the address of current object.
            cout<<"This: "<<this<<endl;
        }
};

int main(){

    // static allocation
    Student s1(56);
    cout<<s1.rollno<<endl;
    cout<<"s1 address: "<<&s1<<endl;


    // dynamic allocation
    Student *s2 = new Student(78);
    cout<<s2->rollno<<endl;

}