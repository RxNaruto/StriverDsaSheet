#include<iostream>
#include <unordered_set>
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
Node* intersectionPoint(Node* head1,Node* head2){
    unordered_set<Node*>st;
    while(head1!=nullptr){
        st.insert(head1);
        head1=head1->next;
    }
    while(head2!=nullptr){
       if(st.find(head2)!=st.end()){
        return head2;
       }
       head2=head2->next;
    }
    return NULL;


}
int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n6->next=n7;
    n7->next=n4;
   
    Node* intersection = intersectionPoint(n1,n6);
    cout<<intersection->data<<endl;
 return 0;
}