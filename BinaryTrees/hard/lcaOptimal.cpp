#include <cstddef>
#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data= val;
        right=left=NULL;
    }

};
Node* lca(Node* root,Node* p,Node* q){
    if(root==NULL || root==p || root==q)return root;

    Node* left = lca(root->left,p,q);
    Node* right = lca(root->right,p,q);
    
    if(left==NULL)return right;
    else if(right==NULL)return left;
    else return root;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right= new Node(5);
    root->right->right = new Node(8);
    root->right->left = new Node(9);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    Node* lcaNode =  lca(root,root->left->left,root->left->right->right);
    cout<<lcaNode->data;
 return 0;
}