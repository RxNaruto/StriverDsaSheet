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
        right = left = NULL;
    }
};
Node* insertANode(Node *root, int key)
{
    if(root==NULL)return new Node(key);
    Node* curr = root;
    while(true){
        if(curr->data<=key){
            if(curr->right==NULL){
                curr->right = new Node(key);
                break;
            }
            else{
                curr=curr->right;
            }
        }
        else{
            if(curr->left==NULL){
                curr->left = new Node(key);
                break;
            }
            else{
                curr = curr->left;
            }
        }
    }
    return root;
}
void inOrderrr(Node* root){
    if(root==NULL)return;
    inOrderrr(root->left);
    cout<<root->data<<" ";
    inOrderrr(root->right);
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
    inOrderrr(root);
    Node* nRoot = insertANode(root,11);
    cout<<endl;
    inOrderrr(nRoot);

    return 0;
}