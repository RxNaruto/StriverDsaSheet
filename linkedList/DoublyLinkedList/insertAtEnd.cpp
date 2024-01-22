#include <iostream>
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
void insertAtEnd(node* &tail,int val){
    node* newtail=new node(val);
    newtail->prev=tail;
    tail->next=newtail;

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
    insertAtEnd(tail,5);
    printingList(head);
    return 0;
}