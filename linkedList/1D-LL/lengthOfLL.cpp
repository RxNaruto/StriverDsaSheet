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
int lengthOfLinkedList(Node* head){
    Node* current=head;
    int length=0;
    while(current!=nullptr){
        length++;
        current=current->next;
    }
    return length;
}
int main()
{
     Node* n1=new Node(1);
     Node* n2=new Node(2);
      Node* n3=new Node(3);
      n1->next=n2;
      n2->next=n3;
      cout<<"The length of linked list is "<<lengthOfLinkedList(n1);
 return 0;
}