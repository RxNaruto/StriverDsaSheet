#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
int main()
{
    node *head = new node(1);
    node *second = new node(2);
    node *third = new node(3);
    node *forth = new node(4);
    node *tail = new node(5);

    head->next = second;
    second->next = third;
    second->prev = head;
    third->next = forth;
    third->prev = second;
    forth->next = tail;
    forth->prev = third;
    tail->prev = forth;
    return 0;
}