#include<iostream>
#include<vector>
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
bool isLeaf(Node* root){
    return !root->left && !root->right;
}

void addLeftBoundary(Node* root, vector<int>&res){
    Node* curr = root->left;
    while(curr){
        if(!isLeaf(curr)){
            res.push_back(curr->data);
        }
        if(curr->left){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
}
void addRightBoundary(Node* root,vector<int>&res){
    Node* curr = root->right;
    vector<int>temp;
    while(curr){
        if(!isLeaf(curr)){
             temp.push_back(curr->data);
        }
        if(curr->right){
            curr=curr->right;
        }
        else{
            curr=curr->right;
        }
    }
    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }

}
void addLeafs(Node* root,vector<int>&res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left){
        addLeafs(root->left,res);
    }
    if(root->right){
        addLeafs(root->right,res);
    }
}
vector<int>printBoundary(Node* root){
    vector<int>res;
    if(!root)return res;
    if(!isLeaf(root)){
        res.push_back(root->data);

    }
    addLeftBoundary(root,res);
    addLeafs(root,res);
    addRightBoundary(root,res);

    return res;


}
int main()
{
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    vector<int>result = printBoundary(root);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
 return 0;
}