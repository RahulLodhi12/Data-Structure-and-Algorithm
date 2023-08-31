#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
        int top;
        int *arr; // points to the first index of array, intially point to the garbage value;
        int size;

        Stack(int s){
            this->size = s;
            arr = new int[s]; // store the actual address of array(first index)
            top = -1;
        }

        void push(int x){
            if(size-top>1){ // atleast one space is empty in stack
                top++;
                arr[top] = x;
            }
            else{
                cout<<"Stack Overflow"<<endl;
            }
        }

        void pop(){
            if(top>=0){ // stack is not empty
                top--;
            }
            else{
                cout<<"Stack Underflow"<<endl;
            }
        }

        int peek(){
            if(top>=0){
                return arr[top];
            }
            else{
                cout<<"Stack is Empty"<<endl;
                return -1;
            }
        }

        bool empty(){
            if(top==-1){
                return true;
            }
            else{
                return false;
            }
        }

};

int main(){

    Stack st(5);

    st.push(11);
    st.push(22);
    st.push(-33);
    st.push(44);

    cout<<st.peek()<<endl; // return 44

    st.pop(); // remove 44 from top

    cout<<st.peek()<<endl; // return -33

    cout<<st.empty()<<endl;; // false(0)

}