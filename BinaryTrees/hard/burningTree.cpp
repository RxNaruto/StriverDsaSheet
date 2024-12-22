#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data = val;
        right= left=NULL;
    }
};
void markParent(Node* root,unordered_map<Node*,Node*>&parent_track){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        if(current->left){
            q.push(current->left);
            parent_track[current->left]=current;
        }
        if(current->right){
            q.push(current->right);
            parent_track[current->right]=current;
        }

    }
}
int timeToBurn(Node* root,Node* target){
    unordered_map<Node* , Node*>parent_track;
    markParent(root,parent_track);
    unordered_map<Node*,bool>visited;
    queue<Node*>q;
    visited[target]=true;
    q.push(target);
    int currLevel=0;
    while(!q.empty()){
        int size = q.size();
        bool anyNewNodesBurned = false;
        for(int i=0;i<size;i++){
            Node* current = q.front();
            q.pop();
            if(current->left && !visited[current->left]){
                q.push(current->left);
                visited[current->left]=true;
                anyNewNodesBurned = true;
            }
            if(current->right && !visited[current->right]){
                q.push(current->right);
                visited[current->right]=true;
                anyNewNodesBurned = true;
            }
            if(parent_track[current] && !visited[parent_track[current]]){
                q.push(parent_track[current]);
                visited[parent_track[current]]=true;
                anyNewNodesBurned = true;
            }
        }
        if(anyNewNodesBurned)currLevel++;

    }
    return currLevel;
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
    cout<<timeToBurn(root, root->right->right );
 return 0;
}