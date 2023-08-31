#include<bits/stdc++.h>
using namespace std;

class dummy{
    public:
        int a;
        int b;
        int *p; //pointer

        dummy(int x, int y, int z){
            this->a = x;
            this->b = y;
            this->p = new int(z);
        }

        dummy(dummy &d){ // own copy constructor
            this->a = d.a;
            this->b = d.b;
            this->p = new int;
            *p = *(d.p);
        }

        void display(){
            cout<<"a: "<<a<<" b: "<<b<<" *p: "<<*p<<endl;
        }
};

int main(){

    dummy d1(3,4,5);
    d1.display();

    dummy d2(d1);
    d2.display();

    cout<<"After changes: "<<endl;

    // change in d1
    d1.a = 11;
    *(d1.p) = 7;
    d1.display();

    // display d2
    d2.display();

}