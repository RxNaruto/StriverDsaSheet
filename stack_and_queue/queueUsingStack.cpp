#include<iostream>
#include<stack>
using namespace std;
class Queue{
    stack<int>s1,s2;
    public:
    void push(int val){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    void pop(){
        s1.pop();
    }
    int front(){
        return s1.top();
    }
   

};
int main()
{
    Queue q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    cout<<q1.front()<<endl;
    q1.pop();
    cout<<q1.front()<<endl;
    q1.pop();

    cout<<q1.front()<<endl;
    q1.pop();
    cout<<q1.front()<<endl;
    q1.pop();
 return 0;
}