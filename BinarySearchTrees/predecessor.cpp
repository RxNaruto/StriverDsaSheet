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
Node *inorderPredecessor(Node *root, int k)
{
    Node *predecessor = NULL;
    while (root != NULL)
    {
        if (root->data < k)
        {
            predecessor = root;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    return predecessor;
}
int main()
{
    Node *root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->left->right->left = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    Node *nRoot = inorderPredecessor(root, 7);
    cout << nRoot->data << endl;
    return 0;
}