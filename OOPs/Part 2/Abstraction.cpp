/*
Abstraction <-> Implementation hiding
*/

/*
Data abstraction is one of the most essential and important features of object-oriented programming in C++. 
Abstraction means displaying only essential information and hiding the details. Data abstraction refers to providing 
only necessary information about the outside world’s data, hiding the background details or implementation. 
Let’s understand abstraction with a real-life example.

Real-life Example:
When you send an email to someone, you just click send, and you get the success message; 
what happens when you click send, how data is transmitted over the network to the recipient is 
hidden from you (because it is irrelevant to you).
*/

#include<bits/stdc++.h>
using namespace std;

class abstraction{
    private:
        int a, b;

    public:
        void set(int x, int y){
            this->a = x;
            this->b = y;
        }

        void display(){
            cout<<"a = "<<a<<endl;
            cout<<"b = "<<b<<endl;
        }
};

int main(){
    abstraction obj;
    obj.set(10,20);
    obj.display();
}

/*
Advantages of Abstraction:
1. Only you can make changes to your data or function, and no one else can.
2. It makes the application secure by not allowing anyone else to see the background details.
3. Increases the reusability of the code.
*/