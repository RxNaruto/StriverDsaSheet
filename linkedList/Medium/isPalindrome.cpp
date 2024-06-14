#include<iostream>
#include<stack>
#include<queue>
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
bool isPalindrome(Node* head){
    Node* current=head;
    stack<int>st;
    queue<int>qe;
    while(current!=nullptr){
         st.push(current->data);
         qe.push(current->data);
         current=current->next;

    }
    while(!st.empty()){
        if(st.top()!=qe.front()){
            return false;
        }
        st.pop();
        qe.pop();
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