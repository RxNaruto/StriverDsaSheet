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
bool checkPath(Node* root,vector<int>&ans,int x){
    if(root==NULL)return false;

    ans.push_back(root->data);
    if(root->data==x)return true;

    if(checkPath(root->left,ans,x) || checkPath(root->right,ans,x))return true;

    ans.pop_back();
    return false;

}
vector<int>getPath(Node* root,int x){
    vector<int>ans;
    if(root==NULL)return ans;

    checkPath(root,ans,x);
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

    vector<int>ans = getPath(root, 7);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    

 return 0;
}