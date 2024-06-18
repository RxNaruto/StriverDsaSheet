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
    int count=0;
    Node* current =head;
    while(current!=nullptr){
        count++;
        current=current->next;

    }
    current = head;
    if(count==n){
        Node* newhead = head->next;
        delete head;
        return newhead;
    }
    int iter = count -n;
    for(int i=0;i<iter-1;i++){
        current=current->next;

    }
    Node* todelete = current->next;
    current ->next = current->next->next;
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