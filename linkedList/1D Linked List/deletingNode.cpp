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
void deleteNode(node* &head,int pos){
    node* current = head;
    for(int i=1;i<pos-1;i++){
        current=current->next;
    }
    
    node* nodetoDelete=current->next;
    current->next=nodetoDelete->next;
    delete nodetoDelete;


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
    deleteNode(head,2); // position is the index of the list starting from the 1
    printingList(head);
 return 0;
}