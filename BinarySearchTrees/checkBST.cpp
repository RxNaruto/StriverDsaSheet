#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;
    
    Node(int val){
        data=val;
        right=left=NULL;
    }
};
bool checkBST(Node* root,long minVal,long maxVal){
    if(root==NULL)return true;
    if(root->data>=maxVal || root->data<=minVal)return false;
    return checkBST(root->left,minVal,root->data) && checkBST(root->right,root->data,maxVal);
   
    
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
    root->right->right = new Node(1);

    cout<<checkBST(root,INT_MIN,INT_MAX);
    
 return 0;
}