#include<iostream>
using namespace std;
class QueueNode{
    public:
    int data;
    QueueNode* next;

    QueueNode(int val){
        data = val;
        next =nullptr;
    }
};
class Queue{
    QueueNode* start;
    QueueNode* end;
    int size;
    
    public:

    Queue(){
        start = nullptr;
        end=nullptr;
        size = 0;
    }
    void push(int val){
        QueueNode* ele = new QueueNode(val);
        if(start==nullptr && end==nullptr){
             start = ele;
             end = ele;
             size++;

        }
        else{
            QueueNode* temp = new QueueNode(val);
            end->next = temp;
            end = temp;
            size++;
        }

    }
    void pop(){
        if(start==nullptr && end == nullptr){
            cout<<"The queue is empty"<<endl;
            return;
        }
        QueueNode* temp = start;
        start = temp->next;
        delete temp;
        size--;
        
    }
    int Top(){
        if(start==nullptr && end == nullptr){
            cout<<"The queue is empty"<<endl;
            return -1;
        }
        int QueueTop = start->data;
        return QueueTop;
       
    }
    int QueueSize(){
        return size;
    }

};

int main()
{
    Queue q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    cout<<q1.Top()<<endl;
     q1.pop();
    cout<<q1.Top()<<endl;
     q1.pop();
    cout<<q1.Top()<<endl;
     q1.pop();
     cout<<q1.Top()<<endl;
     q1.pop();
     


 return 0;
}