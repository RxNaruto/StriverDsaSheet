#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data=val;
        next=nullptr;
        prev=nullptr;
    }
};
void printingList(node *head)
{
    node *current = head;
    while (current!=nullptr)
    {
        cout << current->data << "->";
        current = current->next;
    }
    cout<<"null"<<endl;
}
node* reverseDLL(node* &head){
    node* current = head;
    node* temp = nullptr;
    
    while(current != nullptr){
        // Swap prev and next pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }
    
    // Update head to point to the last node
    if (temp != nullptr) {
        head = temp->prev;
    }

    return head;
}

int main()
{
    node *head = new node(1);
    node *second = new node(2);
    node *third = new node(3);
    node *tail = new node(4);

    head->next = second;
    second->next = third;
    second->prev = head;
    third->next = tail;
    third->prev = second;
    tail->prev = third;
    printingList(head);
    head = reverseDLL(head);
    printingList(head);


 return 0;
}