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
Node* findLastRight(Node* root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
Node* helperNode(Node* root){
    if(root->left==NULL){
        return root->right;
    }
    else if(root->right==NULL){
        return root->left;
    }
    Node* rightChild = root->right;
    Node* lastRight = findLastRight(root->left);
    lastRight->right=rightChild;
    return root->left;

}
Node* deletingNode(Node* root,int key){
    if(root==NULL)return NULL;
    if(root->data==key){
        return helperNode(root);

    }
    Node* curr = root;
    while(curr!=NULL){
        if(curr->data>key){
            if(curr->left!=NULL && curr->left->data==key){
                curr->left = helperNode(curr->left);
                break;
            }
            else{
                curr = curr->left;
            }

        }else{
            if(curr->right!=NULL && curr->right->data==key){
                curr->right = helperNode(curr->right);
                break;
            }
            else{
                curr = curr->right;
            }
        }
    }
    return root;
}
void inOrderrr(Node* root){
    if(root==NULL)return;
    inOrderrr(root->left);
    cout<<root->data<<" ";
    inOrderrr(root->right);
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
    inOrderrr(root);
    cout<<endl;
    Node* nRoot = deletingNode(root,10);
    inOrderrr(nRoot);
    
 return 0;
}