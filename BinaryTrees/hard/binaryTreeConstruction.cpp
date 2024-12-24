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
Node* bTree(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int inStart,int inEnd, map<int,int>inMap){
    if(preStart>preEnd || inStart>inEnd)return NULL;
    Node* root = new Node(preorder[preStart]);
    int inRoot= inMap[root->data];
    int numsLeft = inRoot - inStart;
    root->left = bTree(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,inMap);
    root->right = bTree(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,inMap);
    return root;
}
Node* buildTree(vector<int>&preorder,vector<int>&inorder){
    map<int,int>inMap;
    for(int i=0;i<inorder.size();i++){
        inMap[inorder[i]]=i;
    }
    Node* root = bTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
    return root;
}
int main()
{
    vector<int>inorder = {9,3,15,20,7};
    vector<int>preorder = {3,9,20,15,7};
    
 return 0;
}