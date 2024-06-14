//iterative method
#include<iostream>
using namespace std;
class Node{
      public:
    int data;
    Node* next;
    Node(int val){
         data=val;
         next=nullptr;

    }
};

void printLL(Node* head){
    Node* current = head;
    while(current!=nullptr){
        cout<<current->data<<"->";
        current=current->next;
    }
    cout<<"NULL"<<endl;
}

Node* reverseLLIterative(Node* head){
    Node* temp = head;
    Node* prev = nullptr;
    Node* front = nullptr;
    while(temp!=nullptr){
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
        
    }
return prev;
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
    printLL(n1);
    Node* newHead = reverseLLIterative(n1);
    printLL(newHead);
   
 return 0;
}