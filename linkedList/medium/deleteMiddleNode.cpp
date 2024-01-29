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
void deleteNode(node* &head){
    int pos = middleOfLinkedList(head);
    node* current = head;
    for(int i=1;i<pos-1;i++){
        current=current->next;
    }
    
    node* nodetoDelete=current->next;
    current->next=nodetoDelete->next;
    delete nodetoDelete;


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
    node *forth = new node(4);
    node *tail = new node(5);

    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = tail;
    printingList(head);
    deleteNode(head);
    printingList(head);



 return 0;
}