#include<iostream>
#include<queue>
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
int widthOfTree(Node* root){
    if(!root)return 0;
    int ans = 0;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        int size = q.size();
        int mmin = q.front().second;
        int first,last;
        for(int i=0;i<size;i++){
            int curr_id = q.front().second-mmin;
            Node* temp = q.front().first;
            q.pop();

            if(i==0){
                first=curr_id;
            }
            if(i==size-1){
                last = curr_id;
            }
            if(temp->left){
                q.push({temp->left,2*curr_id+1});
            }
            if(temp->right){
                q.push({temp->right,2*curr_id+2});
            }

        }
        ans = max(ans,last-first+1);


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
    root->right->right = new Node(7);
    root->right->left = new Node(6);
    cout<<widthOfTree(root);
 return 0;
}