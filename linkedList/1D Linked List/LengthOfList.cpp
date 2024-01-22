#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next=nullptr;
    }
};

int lengthOfList(node* head){
    int count =0;
    node* current= head;
    while(current!=nullptr){
        current=current->next;
         count++;
        
    }
    return count;
    
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
    cout<<"The length of linked list is "<<lengthOfList(head);
   
 return 0;
}