#include<iostream>
using namespace std;
int n=10;
class Stack{
    int top;
    int* arr;
    

    public:
    Stack(){
        arr = new int[n];
        top=-1;
    }
    void push(int val){
        if(top==(n-1)){
            cout<<"Stack overflow"<<endl;
            return;
        }
        top++;
        arr[top]=val;
    }
    int Top(){
       if(top==-1){
        cout<<"The stack is empty"<<endl;
        return -1;
       }
       return arr[top];
    }

    void pop(){
        if(top==-1){
        cout<<"The stack is empty"<<endl;
        return;
       }
       top--;
    }
    bool isEmpty(){
         if(top==-1){
        
        return true;
       }
       return false;
    }
    int size(){
         if(top==-1){
        cout<<"The stack is empty"<<endl;
        return 0;
       }
       return top;
    }
};
int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
 return 0;
}