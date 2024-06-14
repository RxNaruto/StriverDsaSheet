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
Node* reverseLLIterative(Node* head){
    Node* temp = head;
    Node* prev = nullptr;
    Node* front = nullptr;
    while(temp!=nullptr){
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
        
    }
return prev;
}

bool isPalindrome(Node* head){
    Node* slow =head;
    Node* fast = head;
    while( fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newHead = reverseLLIterative(slow->next);
    Node* first= head;
    Node* second = newHead;
    while(second!=nullptr){
        if(first->data!=second->data){
            reverseLLIterative(newHead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    return true;
}
int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(2);
    Node* n5 = new Node(1);

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
   
    cout<<"is Palindrome ? "<<isPalindrome(n1);
   
 return 0;
}