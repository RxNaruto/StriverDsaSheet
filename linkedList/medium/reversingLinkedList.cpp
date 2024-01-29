#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next = nullptr;
    }
};
void printingList(node *head)
{
    node *current = head;
    while (current!=nullptr)
    {
        cout << current->data << "->";
        current = current->next;
    }
    cout<<"null"<<endl;
}
void reverseLinkedList(node* &head){
    node *current = head;
    node *prev = nullptr;
    node *nextptr = nullptr;  // Initialize nextptr to nullptr

    while(current != nullptr){
        nextptr = current->next;
        current->next = prev;
        prev = current;
        current = nextptr;
    }

    head = prev;
}

int main()
{
    node *head = new node(1);
    node *second = new node(2);
    node *third = new node(3);
    node *tail = new node(4);

    head->next = second;
    second->next = third;
    third->next = tail;
    printingList(head);
    reverseLinkedList(head);
    printingList(head);
   
 return 0;
}