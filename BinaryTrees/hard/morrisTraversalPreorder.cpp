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
    vector<int>preorder;
    if(root==NULL)return preorder;
    Node* curr = root;
    while(curr!=NULL){
        if(curr->left==NULL){
            preorder.push_back(curr->data);
            curr=curr->right;
        }
        else{
            Node* prev = curr->left;
            while(prev->right && prev->right!=curr){
                prev= prev->right;

            }
            if(prev->right==NULL){
                prev->right = curr;
                preorder.push_back(curr->data);
                curr = curr->left;

            }
            else{
                prev->right=NULL;
                curr=curr->right;
            }
        }
    }
    return preorder;

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
    vector<int>preorder = morrisTraversal(root);
    for(int i=0;i<preorder.size();i++){
        cout<<preorder[i]<<" ";
    }

 return 0;
}