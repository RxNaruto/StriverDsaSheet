#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *right;
    Node *left;

    Node(int val)
    {
        data = val;
        right = left = NULL;
    }
};
int ceil(Node *root, int key)
{
    int ceilV = -1;
    while (root!= NULL)
    {
        if (root->data == key)
        {
            ceilV = root->data;
            return ceilV;
        }
        else if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            ceilV = root->data;
            root = root->left;
             

        }
    }
    return ceilV;
}
int main()
{
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->left->right->left = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    cout<<ceil(root,11);
    return 0;
}