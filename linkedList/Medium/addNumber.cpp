#include<iostream>
using namespace std;
class Node{
    public: 
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
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
Node* reverseLL(Node* head){
    Node* current=head;
    Node* prev =nullptr;

    while(current!=nullptr){
        Node* temp = current->next;
        current->next = prev;
        prev= current;
        current = temp;
    }
    return prev;
}
Node* addNumbers(Node* head){
    Node* nhead = reverseLL(head);
    Node* temp = nhead;
    int carry = 1;
    while(temp!=nullptr){
        temp->data = temp->data+carry;
        if(temp->data <10){
            carry = 0;
            break;
        }
        else{
            temp->data = 0;
            carry = 1;
        }
        temp=temp->next;
        
    }
    if(carry == 1){
        Node* newNode = new Node(1);
        nhead = reverseLL(nhead);
        newNode->next = nhead;
        return newNode;
    }
    nhead = reverseLL(nhead);
    return nhead;
}
int main()
{
    Node* n1 = new Node(9);
    Node* n2 = new Node(9);
    Node* n3 = new Node(9);
    n1->next = n2;
    n2->next =n3;
    
    printLL(n1);
    Node* nhead = addNumbers(n1);
    printLL(nhead);
    
 return 0;
}