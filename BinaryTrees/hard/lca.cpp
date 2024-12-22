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
bool checkPath(Node* root,vector<int>&ans,int x){
    if(root==NULL)return false;

    ans.push_back(root->data);
    if(root->data==x)return true;
    if(checkPath(root->left,ans,x)|| checkPath(root->right,ans,x))return true;

    ans.pop_back();
    return false;
}
vector<int>getPath(Node* root,int x){
    vector<int>ans;
    if(root==NULL)return ans;

    checkPath(root,ans,x);
    return ans;


}
int lca(Node* root,int x,int y){
     vector<int>a=getPath(root,x);
     vector<int>b=getPath(root,y);
     int k=0;
     while(k<a.size() && k<b.size()){
        if(a[k]!=b[k]){
            return a[k-1];
        }
        k++;
     }
     return -1;
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

    cout<<lca(root,4,7);
 return 0;
}