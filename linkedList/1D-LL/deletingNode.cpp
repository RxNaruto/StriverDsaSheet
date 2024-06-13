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
void deletingNode(Node* head){
    Node* current=head;
    while(current->next->next!=nullptr){
        current=current->next;

    }
    Node* todelete=current->next;
    current->next=current->next->next;
    delete todelete;
    

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
      deletingNode(n1);
      printLL(n1);
 return 0;
}