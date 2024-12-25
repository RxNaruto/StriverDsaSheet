#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data = val;
        right = left = NULL;
    }
};
Node* build(vector<int>&A,int& i,int bound){
    if(i==A.size() || A[i]>bound)return NULL;
    Node* root = new Node(A[i++]);
    root->left = build(A,i,root->data);
    root->right = build(A,i,bound);
    return root;

}
Node* bstPreorder(vector<int>A){
    int i=0;
    return build(A,i,INT_MAX);

}
void inOrderrr(Node* root){
    if(root==NULL)return;
    inOrderrr(root->left);
    cout<<root->data<<" ";
    inOrderrr(root->right);
}
int main()
{
    vector<int>preorder = {8,5,1,7,10,12};
    Node* root = bstPreorder(preorder);
    inOrderrr(root);

 return 0;
}