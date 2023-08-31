#include<bits/stdc++.h>
using namespace std;

class Student{
    private:
        int marks;
    public:
        string name;
        int rollno;

        int getData(int m){
            this->marks = m;
            return this->marks;
        }
};

int main(){

    Student s1;
    cout<<s1.getData(44)<<endl;

}
/*
Encapsulation :– 
1. Wrapping data and functions into a single unit.
2. In fully encapsulated class, all the data members are marked private, provide data hiding feature.
3. Encapsulation <-> Information hiding/ Data hiding

Advantage :-
1. Data hiding through private data member, increase security.
2. By encapsulation, we can make class read-only.
3. Encapsulation code is better for unit testing.
4. Code Reusability
*/