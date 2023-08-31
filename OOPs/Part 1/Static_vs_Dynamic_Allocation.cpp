#include<bits/stdc++.h>
using namespace std;

class Student{
    private:
        int marks;
    public:
        string name;
        int rollno;
};

int main(){
    // static allocation-> allocated in stack
    Student s1;
    s1.rollno = 88;
    cout<<"s1 rollno.: "<<s1.rollno<<endl;

    // dynamic allocation-> allocated in heap; s2 is act as pointer
    Student *s2 = new Student(); 
    s2->rollno = 89;
    cout<<"s2 rollno.: "<<s2->rollno<<endl;
    //          OR
    cout<<"s2 rollno.: "<<(*s2).rollno<<endl;
}