#include<iostream>
#include<unordered_map>
#include<queue>
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
void markParent(Node* root,unordered_map<Node* , Node*>&parent_track,Node* target){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        if(current->left){
            parent_track[current->left]=current;
            q.push(current->left);
        }
        if(current->right){
            parent_track[current->right]=current;
            q.push(current->right);
        }
    }
}
vector<int>distanceK(Node* root,Node* target,int k){
    unordered_map<Node* , Node*>parent_track;
    markParent(root,parent_track,target);
    unordered_map<Node*,bool>visited;
    queue<Node*>q;
    q.push(target);
    int currLevel=0;
    visited[target]=true;
    while(!q.empty()){
        int size = q.size();
        if(currLevel++==k)break;

    }
}
int main()
{
 return 0;
}