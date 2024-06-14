
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

bool loopDetection(Node* head){
    Node* hare = head;
    Node* tortoise = head;
    while(hare!=nullptr && hare->next!=nullptr){
        hare=hare->next->next;
        tortoise=tortoise->next;
        if(hare==tortoise){
            return true;
        }

    }
    return false;
}

int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
     Node* n5 = new Node(5);


    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n3;
  
   cout<<"Presence of loop "<<loopDetection(n1);
   
 return 0;
}