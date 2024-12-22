#include <cstddef>
#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data= val;
        right=left=NULL;
    }

};
int cntLeftHeight(Node* root){
    int hgt = 0;
    while(root){
        hgt++;
        root=root->left;

    }
    return hgt;
}
int cntRightHeight(Node* root){
    int hgt = 0;
    while(root){
        hgt++;
        root=root->right;

    }
    return hgt;
}
int cntNodes(Node* root){
    if(root==NULL)return 0;
    int lh = cntLeftHeight(root);
    int rh = cntRightHeight(root);
    if(lh==rh){
        return (1<<lh)-1;
    }
    return 1+cntNodes(root->left)+cntNodes(root->right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right= new Node(5);
    root->right->right = new Node(8);
    root->right->left = new Node(9);
    
    cout<<cntNodes(root);

   
 return 0;
}