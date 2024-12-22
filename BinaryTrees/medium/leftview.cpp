#include<iostream>
#include<vector>
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
vector<int>leftView(Node* root,int level,vector<int>&ans){
    
    if(root==NULL)return ans;
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    leftView(root->left,level+1,ans);
    leftView(root->right, level+1,ans);
    

    return ans;

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
    vector<int>ans;
    vector<int>res = leftView(root,0,ans);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }

 return 0;
}