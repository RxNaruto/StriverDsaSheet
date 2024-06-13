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
Node* insertAtBeg(Node* head,int val){
    Node* newhead = new Node(val);
    newhead->next=head;
    head = newhead;
    return head;

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
    Node* n1=new Node(1);
     Node* n2=new Node(2);
      Node* n3=new Node(3);
      n1->next=n2;
      n2->next=n3;
      printLL(n1);
      Node* newHead =insertAtBeg(n1,0);
      printLL(newHead);


 return 0;
}