#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
    }
};
int loopDetection(node* head){
    node* slow = head;
    node* fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow == fast){
            return 1;
        }
    }
    return -1;
}
int main()
{
    node *head = new node(1);
    node *second = new node(2);
    node *third = new node(3);
    node *forth = new node(4);
    node *fifth = new node(5);
    node *sixth = new node(6);
    node *seventh = new node(7);
    node *eight = new node(8);

    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eight;
    eight->next = forth;

    cout<<"Presence of loop "<<loopDetection(head);


 return 0;
}