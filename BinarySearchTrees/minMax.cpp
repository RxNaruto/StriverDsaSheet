#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        right=left=NULL;
    }
};
Node* min(Node* root){
    if(root==NULL)return NULL;
    while(root->left!=NULL){
         root = root->left;
    }
   return root;
    
    
}
Node* max(Node* root){
    if(root==NULL)return NULL;
    while(root->right!=NULL){
         root = root->right;
    }
   return root;
    
    
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
    Node* ansMin = min(root);
    cout<<ansMin->data<<endl;
    Node* ansMax = max(root);
    cout<<ansMax->data<<endl;
    
 return 0;
}