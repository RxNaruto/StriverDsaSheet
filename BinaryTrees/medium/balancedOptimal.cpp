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
int balanced(Node* root){
    if(root==nullptr)return 0;
    int lh = balanced(root->left);
    if(lh==-1)return -1;
    int rh = balanced(root->right);
    if(rh==-1)return -1;
    if(abs(lh-rh)>1)return -1;
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
    root->right->left->left = new Node(6);
    root->right->left->left->left = new Node(6);
    cout<<balanced(root);
 return 0;
}