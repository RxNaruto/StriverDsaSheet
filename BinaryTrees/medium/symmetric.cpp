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
bool checkSymmetric(Node* left,Node* right){
    if(left==NULL || right==NULL)return left==right;

    if(left->data!=right->data)return false;
    return checkSymmetric(left->left ,right->right)&&checkSymmetric(left->right,right->left);
}
bool isSymmetric(Node* root){
    return root==NULL || checkSymmetric(root->left,root->right);
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(4);
    root->left->right= new Node(5);
    root->right->right = new Node(40);
    root->right->left = new Node(5);
    cout<<isSymmetric(root);
 return 0;
}