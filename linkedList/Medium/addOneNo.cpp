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

int main()
{
    Node* n1=new Node(2);
     Node* n2=new Node(4);
      Node* n3=new Node(3);

      
      n1->next=n2;
      n2->next=n3;

      Node* a1=new Node(5);
     Node* a2=new Node(6);
      Node* a3=new Node(4);

      
      a1->next=a2;
      a2->next=a3;
    
    printLL(newHead);
    
   
      
      


 return 0;
}