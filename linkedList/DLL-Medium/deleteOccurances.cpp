#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
Node *deleteOccurances(Node *head, int key)
{
    Node *nextNode = head;
    Node *prevNode = nullptr;
    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            if (temp == head)
            {
                head = head->next;
            }
            nextNode = temp->next;
            prevNode = temp->prev;
            if (nextNode)
                nextNode->prev = prevNode;
            if (prevNode)
                prevNode->next = nextNode;
            free(temp);
            temp = nextNode;
        }else{
            temp = temp->next;
        }
    }return head;
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
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(0);
    Node* n4 = new Node(1);
    Node* n5 = new Node(3);
    Node* n6 = new Node(0);
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    n4->next = n5;
    n5->prev = n4;
    n5->next = n6;
    n6->prev =n5;

    Node* newHead = deleteOccurances(n1,1);
    printLL(newHead);



    return 0;
}