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
Node* addTwoNum(Node* head1,Node* head2){
    Node* temp1=head1;
    Node* temp2=head2;
    Node* dummyNode = new Node(-1);
    Node* current= dummyNode;
    int carry=0;
    while(temp1!=nullptr || temp2!=nullptr){
        int sum=carry;
        if(temp1)sum=sum+temp1->data;
        if(temp2)sum=sum+temp2->data;
        Node* newNode = new Node(sum%10);
        carry=sum/10;
        current->next=newNode;
        current=current->next;
        if(temp1){
            temp1=temp1->next;
        }
        if(temp2){
            temp2=temp2->next;
        }
        
    }
    if(carry){
        Node* newNode = new Node(carry);
        current->next=newNode;
    }
    
    return dummyNode->next;
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
    Node* newHead = addTwoNum(n1,a1);
    printLL(newHead);
    
   
      
      


 return 0;
}