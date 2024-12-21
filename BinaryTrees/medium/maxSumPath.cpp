#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};
int maxSumPath(Node* root,int& maxS){
    if(root==NULL)return 0;
    int leftSum=maxSumPath(root->left,maxS);
    int rightSum=maxSumPath(root->right,maxS);
    maxS= max(root->data+leftSum+rightSum,maxS);
    return (root->data)+max(leftSum,rightSum);
   
}
int maxSum(Node* root){
    int maxS=0;
    maxSumPath(root,maxS);
    return maxS;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    root->right->left = new Node(6);

    cout << maxSum(root);
 return 0;
}