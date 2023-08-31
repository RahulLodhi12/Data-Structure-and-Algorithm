#include<bits/stdc++.h>
using namespace std;

// Access Modifer -> Public, Private and Protect. By default, access modifer in class is "private".

class Student{
    //Data member
    private:
        int marks;
    
    public:  // access modifer
        int rollno;
        string name;
    
    //Member function/method
    void display(int marks){ // this is also public as it is under pubic.
        cout<<marks<<endl;
    }

};

int main(){

    Student s1;

    // To access data member, we use "." operator
    s1.rollno = 546009; // assigned
    s1.name = "Rahul Lodhi";
    // s1.marks = 55;
    cout<<"Rollno.: "<<s1.rollno<<endl; // print garbage value, when no value is assigned to object(s1)
    cout<<"Name: "<<s1.name<<endl;
    // cout<<"Marks: "<<s1.marks<<endl; // print garbage value, when no value is assigned to object(s1)

    s1.display(55);
}

/*
Public Access Modifier in C++ :-
All the variables and functions declared under public access modifier will be available for everyone. 
They can be accessed both inside and outside the class. Dot (.) operator is used in the program to 
access public data members directly.

Private Access Modifier in C++
All the variables and functions declared under a private access modifier can only be used inside the class. 
They are not permissible to be used by any object or function outside the class.


*/