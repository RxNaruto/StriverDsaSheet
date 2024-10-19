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
Node* sort012(Node* head){
    if(head==nullptr || head->next==nullptr)return head;
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead  = new Node(-1);

    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;

    Node* temp  = head;
    while(temp!=nullptr){
        if(temp->data ==0){
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data ==1){
            one->next = temp;
            one= temp;
        }
        else{
            two->next = temp;
            two = temp;
        }
        temp= temp->next;
    }
    zero->next = oneHead->next;
    one->next = twoHead->next;
    two->next = nullptr;
    return zeroHead->next;


}

  

int main()
{
    Node* n1=new Node(1);
     Node* n2=new Node(0);
      Node* n3=new Node(2);
      Node* n4=new Node(0);
     Node* n5=new Node(1);
      Node* n6=new Node(2);
      n1->next=n2;
      n2->next=n3;
      n3->next=n4;
      n4->next=n5;
      n5->next=n6;
      printLL(n1);
      Node* nhead = sort012(n1);
      printLL(nhead);
      
      
    
      


 return 0;
}