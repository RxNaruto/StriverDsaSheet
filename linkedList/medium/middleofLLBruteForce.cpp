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
int middleoflinkedList(node* head){
    int count=0,mid1;
    node* current = head;
    while(current!=nullptr){
        count++;
        current=current->next;
    }
    if(count%2==0){
        mid1=count/2;
       
        
    }
    else{
        mid1=(count/2)+1;
    }
    current=head;
    for(int i=1;i<mid1;i++){
        current=current->next;

    }
    return current->data;


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

    cout<<"The middle element of the linked list is "<<middleoflinkedList(head);
 return 0;
}