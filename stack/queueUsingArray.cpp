#include<iostream>
using namespace std;
int n=10;
class queue{
    int front;
    int back;
    int* arr;

    public:
    
    queue(){
        front = -1;
        back = -1;
        arr = new int[n];
    }
    void push(int val){
        if(back==(n-1)){
            cout<<"queue is full"<<endl;
            return;
        }
        if(front==-1){
            front++;
        }
        back++;
        arr[back]=val;
    }
    void pop(){
        if(front==-1 || front>back){
            cout<<"The queue is empty"<<endl;
            return;
        }
        front++;

    }
    int top(){
        if(front==-1 || front>back){
            cout<<"The queue is empty"<<endl;
            return -1;
        }
        return front;
    }
    int size(){
        if(front==-1 || front>back){
            cout<<"The queue is empty"<<endl;
            return -1;
        }
        return back;
    }

};
int main()
{
    queue q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    cout<<q1.top()<<endl;
    q1.pop();
    cout<<q1.top()<<endl;
    q1.pop();
    cout<<q1.top()<<endl;
    q1.pop();
    cout<<q1.top()<<endl;
    
 return 0;
}