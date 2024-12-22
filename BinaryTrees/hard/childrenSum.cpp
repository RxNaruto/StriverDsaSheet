#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left=right=NULL;
    }
};
void childrenSum(Node* root){
    if(root==NULL)return;
    int child =0;

    if(root->left){
      child+=root->left->data;
    }
    if(root->right){
        child+=root->right->data;
    }
    if(child>=root->data){
        root->data = child;
    }
    else{
        if(root->left){
            root->left->data = root->data;
        }
        else if(root->right){
            root->right->data = root->data;
        }
    }
    childrenSum(root->left);
    childrenSum(root->right);

    int tot=0;
    if(root->left){
        tot+=root->left->data;
    }
    if(root->right){
        tot+=root->right->data;
    }
    if(root->left ||  root->right){
        root->data=tot;
    }
}
void inOrder(Node* root){
    if(root==NULL)return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
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
    inOrder(root);
    childrenSum(root);
    cout<<endl;
    inOrder(root);
 return 0;
}