#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=right=NULL;
    }
};
int levelOrder(Node* root){
    if(root==NULL)return 1;
    queue<Node*>q;
    q.push(root);
    int cnt=0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            Node* dummy = q.front();
            q.pop();
            if(dummy->left){
                q.push(dummy->left);
            }
            if(dummy->right){
                q.push(dummy->right);
            }
            
        }
        cnt++;
    }
    return cnt; 


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
    cout<<levelOrder(root);
 return 0;
}