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
void markParent(Node* root,unordered_map<Node* , Node*>&parent_track){
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
    markParent(root,parent_track);
    unordered_map<Node*,bool>visited;
    queue<Node*>q;
    q.push(target);
    int currLevel=0;
    visited[target]=true;
    while(!q.empty()){
        int size = q.size();
        if(currLevel++==k)break; // compare and increase the currLevel
        for(int i=0;i<size;i++){
            Node* current = q.front();
            q.pop();
            if(current->left && !visited[current->left]){
                q.push(current->left);
                visited[current->left]=true;
            }
            if(current->right && !visited[current->right]){
                q.push(current->right);
                visited[current->right]=true;
            }
            if(parent_track[current] && !visited[parent_track[current]]){
                q.push(parent_track[current]);
                visited[parent_track[current]]=true;
            }
        }
        

    }
    vector<int>result;
        while(!q.empty()){
            result.push_back(q.front()->data);
            q.pop();
        }
        return result;
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

    vector<int>res = distanceK(root,root->left,1);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
 return 0;
}