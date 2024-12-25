#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        right=left=NULL;
    }
};
Node* search(Node* root,int val){
    while(root!=NULL && root->data!=val){
        root = val< root->data?root->left:root->right; 
    }
    return root;
    
    
}
int main()
{
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->left->right->left = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    Node* ans = search(root,12);
    cout<<ans->data<<endl;
    
 return 0;
}