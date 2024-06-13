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
void insertNode(Node* head,int val){
    Node* current = head;
    while(current->next!=nullptr){
        current=current->next;
    }
    Node* newNode= new Node(val);
    newNode->prev=current;
    current->next=newNode;
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
    printLL(n1);
    insertNode(n1,5);
    printLL(n1);
   
 return 0;
}