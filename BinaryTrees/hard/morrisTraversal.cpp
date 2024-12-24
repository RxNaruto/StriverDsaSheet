#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data= val;
        right = left = NULL;
    }
};
vector<int>morrisTraversal(Node* root){
    vector<int>inorder;
    if(root==NULL)return inorder;
    Node* curr = root;
    while(curr!=NULL){
        if(curr->left==NULL){
            inorder.push_back(curr->data);
            curr=curr->right;
        }
        else{
            Node* prev = curr->left;
            while(prev->right && prev->right!=curr){
                prev= prev->right;

            }
            if(prev->right==NULL){
                prev->right = curr;
                curr = curr->left;

            }
            else{
                prev->right=NULL;
                inorder.push_back(curr->data);
                curr=curr->right;
            }
        }
    }
    return inorder;

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
    vector<int>inorder = morrisTraversal(root);
    for(int i=0;i<inorder.size();i++){
        cout<<inorder[i]<<" ";
    }

 return 0;
}