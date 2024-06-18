//replacing data
#include<iostream>
#include<vector>
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
void oddAndEven(Node* head){
    vector<int>arr;
    Node* temp = head;
    while(temp!=nullptr && temp->next!=nullptr){
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp){
        arr.push_back(temp->data);
    }
    temp=head->next;
    while(temp!=nullptr && temp->next!=nullptr){
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp){
        arr.push_back(temp->data);
    }
    temp = head;
    int i=0;
    while(temp!=nullptr ){
        temp->data=arr[i];
        i++;
        temp=temp->next;
    }




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
      oddAndEven(n1);
      printLL(n1);
    
      


 return 0;
}