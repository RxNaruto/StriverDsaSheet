#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class Solution
{
public:
    Node *prev = NULL;
    void flateningTree(Node *root)
    {
        if (root == NULL)
            return;
        flateningTree(root->right);
        flateningTree(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }

};

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    sol.flateningTree(root);
    while(root!=NULL){
        cout<<root->data<<"->";
        root=root->right;
    }
    return 0;
}