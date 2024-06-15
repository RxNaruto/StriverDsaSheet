#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
         data=val;
         next=nullptr;
         prev=nullptr;
    }
};

Node* middleOfLL(Node* head){
    Node* slow =head;
    Node* fast = head;
    while( fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
       
           
      
    }
     return slow;
}
void deleteMiddleNode(Node* head){
    Node* temp = middleOfLL(head);
    temp

}
int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5= new Node(5);
    

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n2->prev=n1;
    n3->prev=n2;
    n4->prev=n3;
    n5->prev=n4;
    
    cout<<"The middle of LL is " << middleOfLL(n1);

    
   
 return 0;
}