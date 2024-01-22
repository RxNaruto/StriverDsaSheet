#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = nullptr;
    }
};
bool searchingLinkedList(node *head, int val)
{
    node *current = head;
    while (current != nullptr)
    {
        if (current->data == val)
        {
            return true;
            break;
        }
        else
        {
            current = current->next;
        }
    }
    return false;
}
int main()
{
    node *head = new node(1);
    node *second = new node(2);
    node *third = new node(3);
    node *tail = new node(4);

    head->next = second;
    second->next = third;
    third->next = tail;
    cout<<"The presence of element 6 is "<<searchingLinkedList(head,6);
    return 0;
}