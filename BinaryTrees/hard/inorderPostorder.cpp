#include<iostream>
#include<vector>
#include<map>
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
Node* bTree(vector<int>&postorder,int postStart,int postEnd,vector<int>&inorder,int inStart,int inEnd, map<int,int>inMap){
    if(postStart>postEnd || inStart>inEnd)return NULL;
    Node* root = new Node(postorder[postEnd]);
    int inRoot= inMap[postorder[postEnd]];
    int numsLeft = inRoot - inStart;
    root->left = bTree(postorder,postStart,postStart+numsLeft-1,inorder,inStart,inRoot-1,inMap);
    root->right = bTree(postorder,postStart+numsLeft,postEnd-1,inorder,inRoot+1,inEnd,inMap);
    return root;
}
Node* buildTree(vector<int>&postorder,vector<int>&inorder){
    map<int,int>inMap;
    for(int i=0;i<inorder.size();i++){
        inMap[inorder[i]]=i;
    }
    Node* root = bTree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inMap);
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
    vector<int>inorder = {9,3,15,20,7};
    vector<int>postorder = {3,9,20,15,7};
    Node* root = buildTree(postorder,inorder);
    inOrderrr(root);



    
 return 0;
}