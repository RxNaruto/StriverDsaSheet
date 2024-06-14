
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

int lengthOfLoop(Node* head){
    Node* hare = head;
    Node* tortoise = head;
    while(hare!=nullptr && hare->next!=nullptr){
       
        tortoise=tortoise->next;
         hare=hare->next->next;
        if(hare==tortoise){
            tortoise=head;
            while(hare!=tortoise){
            hare=hare->next;
            tortoise=tortoise->next;
            }
            tortoise=tortoise->next;
            int count =1;
            while(hare!=tortoise){
                count++;
                tortoise=tortoise->next;
            }
            return count;
           
        }
        

    }
    return 0;
  
    
    
 
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

   cout<<"length of loop "<< lengthOfLoop(n1) <<endl;
   
 return 0;
}