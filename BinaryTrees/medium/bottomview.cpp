#include<iostream>
#include<map>
#include<vector>
#include<queue>
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
vector<int>bottomview(Node* root){
    vector<int>ans;
    if(root==NULL)return ans;
    map<int,int>mpp;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        Node* node = p.first;
        int line = p.second;

        mpp[line]=node->data;
        if(node->left){
            q.push({node->left,line-1});
        }
        if(node->right){
            q.push({node->right,line+1});
        }

    }
    for(auto it : mpp){
        ans.push_back(it.second);
    }
    return ans;
    
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->left->left = new Node(4);
    root->right->right = new Node(7);
    root->right->left = new Node(6);

  vector<int>ans = bottomview(root);
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }

 return 0;
}