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
void insertAtBeg(node* &head, int val){
    node* newhead= new node(val);
    newhead->next = head;
    head= newhead;
}
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
     cout<<"The linked list after addition of new node"<<endl;
     insertAtBeg(head,0);
     printingList(head);
 return 0;
}