#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=nullptr;
    }
};
int middleOfLinkedList(node* head){
    node* tortoise = head;
    node* hare = head;
    while(hare->next!=nullptr){
        tortoise=tortoise->next;
        hare=hare->next->next;
    }
    return tortoise->data;
}
int main()
{
     node *head = new node(1);
    node *second = new node(2);
    node *third = new node(3);
    node *forth = new node(4);
    node *tail = new node(5);

    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = tail;

    cout<<"The middle element of the linked list is "<<middleOfLinkedList(head);
 return 0;
}