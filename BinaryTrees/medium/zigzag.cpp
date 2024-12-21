#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        right=left=NULL;
    }
};
vector<vector<int>>zigzag(Node* root){
    vector<vector<int>>ans;
    if(root==NULL)return ans;
    queue<Node*>q1;
    q1.push(root);
    int flag=0;
    while(!q1.empty()){
         vector<int>level;
        int size = q1.size();
        for(int i=0;i<size;i++){
            Node* current = q1.front();
            q1.pop();
           
            if(current->left)q1.push(current->left);
            if(current->right)q1.push(current->right);
            level.push_back(current->data);

        }
        if(!flag){
        ans.push_back(level);
        
        }
        else{
            reverse(level.begin(),level.end());
            ans.push_back(level);
            
        }
        flag=!flag;
    }
    return ans;
}
int main()
{

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right = new Node(7);
    
    vector<vector<int>>ans = zigzag(root);
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