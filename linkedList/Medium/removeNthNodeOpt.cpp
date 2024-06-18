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
Node* removeNthNode(Node* head,int n){
  
   Node* fast =head;
   Node* slow = head;
   for(int i=0;i<n;i++){
    fast=fast->next;

   }
   while(fast->next!=nullptr){
    fast=fast->next;
    slow=slow->next;
   }
   if(fast==nullptr){
    Node* newhead = head->next;
    delete head;
    return newhead;
   }
   Node* todelete= slow->next;
   slow->next = slow->next->next;
   delete todelete;
   return head;
}


int main()
{
    Node* n1=new Node(1);
     Node* n2=new Node(2);
      Node* n3=new Node(3);
      Node* n4=new Node(4);
     Node* n5=new Node(5);
      
      n1->next=n2;
      n2->next=n3;
      n3->next=n4;
      n4->next=n5;
   
      printLL(n1);
      Node* newhead  = removeNthNode(n1,3);
      printLL(newhead);
    
      


 return 0;
}