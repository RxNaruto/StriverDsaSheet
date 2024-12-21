#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left= right=NULL;
    }
};
int maxHeight(Node* root){
    if(root==nullptr)return 0;
    int lh = maxHeight(root->left);
    int rh = maxHeight(root->right);
    return 1+max(lh,rh);
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right= new Node(5);
    root->right->right = new Node(7);
    root->right->left = new Node(6);
    cout<<maxHeight(root);
 return 0;
}