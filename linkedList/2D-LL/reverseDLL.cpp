//stack method
#include<iostream>
#include<stack>
using namespace std;
class Node{
      public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
         data=val;
         next=nullptr;
         prev=nullptr;
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
void reverseDLL(Node* head){
    Node* current = head;
    stack<int>st;
    while(current!=nullptr){
        st.push(current->data);
        current=current->next;
    }
    Node* current2 = head;
    while(!st.empty() && current2!=nullptr){
        current2->data=st.top();
        st.pop();
        current2=current2->next;
    }
     
}
int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n2->prev=n1;
    n3->prev=n2;
    printLL(n1);
    reverseDLL(n1);
    printLL(n1);
   
 return 0;
}