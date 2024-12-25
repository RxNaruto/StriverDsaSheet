#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data=val;
        right= left = NULL;
    }
};
Node* lca(Node* root,Node* p,Node* q){
    if(root==NULL)return NULL;
    int curr = root->data;
    if(curr<p->data && curr<q->data)return lca(root->right,p,q);
    if(curr>p->data && curr>q->data)return lca(root->left,p,q);
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
    Node* lcaRoot =  lca(root,root->left->left,root->left->right);
    cout<<lcaRoot->data<<endl;
 return 0;
}