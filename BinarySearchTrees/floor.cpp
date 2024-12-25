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
int floor(Node *root, int key)
{
    int fv = -1;
    while (root!= NULL)
    {
        if (root->data == key)
        {
            fv = root->data;
            return fv;
            
        }
        else if (root->data < key)
        {
            fv = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
             

        }
    }
    return fv;
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
    cout<<floor(root,9);
    return 0;
}