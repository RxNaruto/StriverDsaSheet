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
Node* reverseDLL(Node* head){
    Node* current = head;
    Node* temp = NULL;
    while(current!=nullptr){
       temp = current->prev;
        current->prev=current->next;
        current->next= temp;
        current=current->prev;
    }
    Node* newHead = temp->prev;
    return newHead;
    
}

void printLL(Node* head){
    Node* current = head;
    while(current!=nullptr){
        cout<<current->data<<"->";
        current=current->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n2->prev=n1;
    n3->prev=n2;
    n4->prev=n3;
 
    printLL(n1);
    Node* newHead = reverseDLL(n1);
    printLL(newHead);

 return 0;
}