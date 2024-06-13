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
int serachElementLL(Node* head,int val){
    Node* current=head;
    int count=0;
    while(current!=nullptr){
        if(current->data!=val){
            count++;
            current=current->next;
        }
        else{
             count++;
             return count;
        }

    }
    return -1;
}
int main()
{
    Node* n1=new Node(1);
     Node* n2=new Node(40);
      Node* n3=new Node(3);
      n1->next=n2;
      n2->next=n3;
      cout<<"The element 40 is present at "<<serachElementLL(n1,40);
 return 0;
}