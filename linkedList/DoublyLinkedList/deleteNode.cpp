#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
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
void nodeToDelete(node* &head,int pos){
    node* current=head;
    for(int i=0;i<pos-1;i++){
        current=current->next;
    }
    current->prev->next=current->next;
    current->next->prev=current->prev;
    delete current;

    
}
int main()
{
    node *head = new node(1);
    node *second = new node(2);
    node *third = new node(3);
    node *tail = new node(4);

    head->next = second;
    second->next = third;
    second->prev = head;
    third->next = tail;
    third->prev = second;
    tail->prev = third;

    printingList(head);
    nodeToDelete(head,2); // position is from the index 1 
    printingList(head);
 return 0;
}