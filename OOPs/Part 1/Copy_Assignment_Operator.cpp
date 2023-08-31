#include<bits/stdc++.h>
using namespace std;

class dummy{
    public:
        int a;
        int b;

        void setData(int x, int y){
            this->a = x;
            this->b = y;
        }
        
        void display(){
            cout<<"a: "<<a<<" b: "<<b<<endl;
        }
};

int main(){

    dummy d1;
    d1.setData(3,4);
    d1.display();

    dummy d2;
    d2 = d1;

    d2.display();

}