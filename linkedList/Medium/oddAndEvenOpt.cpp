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

Node* oddAndEven(Node* head){
     Node* oddhead = head;
     Node* evenhead= head->next;
     Node* even = evenhead;
     while(evenhead!=nullptr && evenhead->next!=nullptr){
        oddhead->next=oddhead->next->next;
        evenhead->next=evenhead->next->next;
        oddhead=oddhead->next;
        
        evenhead=evenhead->next;
        
         
     }
    
     oddhead->next = even;
     return head;

}
  

int main()
{
    Node* n1=new Node(1);
     Node* n2=new Node(2);
      Node* n3=new Node(3);
      Node* n4=new Node(4);
     Node* n5=new Node(5);
      Node* n6=new Node(6);
      n1->next=n2;
      n2->next=n3;
      n3->next=n4;
      n4->next=n5;
      n5->next=n6;
      printLL(n1);
      Node* newhead = oddAndEven(n1);
      printLL(newhead);
    
      


 return 0;
}