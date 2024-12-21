#include<iostream>
#include<vector>
#include<queue>
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
vector<vector<int>>levelOrder(Node* root){
    vector<vector<int>>ans;
    if(root==NULL)return ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            Node* dummy = q.front();
            q.pop();
            if(dummy->left){
                q.push(dummy->left);
            }
            if(dummy->right){
                q.push(dummy->right);
            }
            level.push_back(dummy->data);
        }
        ans.push_back(level);
    }
    return ans; 


}
int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->left->right= new Node(9);
    root->left->left->right->left= new Node(1);
    root->right->right = new Node(6);
    root->right->left = new Node(7);
    root->right->right->left = new Node(8);
    vector<vector<int>>ans = levelOrder(root);
    cout<<"[";
    for(int i =0;i<ans.size();i++){
        cout<<"[";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]";
    }
    cout<<"]";


 return 0;
}