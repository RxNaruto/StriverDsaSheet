#include <cstddef>
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data = val;
        right=left=NULL;
    }
};
int getHeight(Node* root){
    if(root==NULL)return 0;

    int lh=getHeight(root->left);
    int rh=getHeight(root->right);
    return 1+max(lh,rh);
}
bool balanced(Node* root){
    if(root==NULL)return true;

    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    if(abs(lh-rh)<=1 && balanced(root->left) && balanced(root->right))return true;
    return false;
    
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->left = new Node(7);
    cout<<balanced(root);
 return 0;
}