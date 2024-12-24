#include <iostream>
#include<stack>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class Solution
{
public:
    void flateningTree(Node* root){
        Node* curr = root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                Node* prev = curr->left;
                while(prev->right){
                    prev=prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left = NULL;
            }
            
            curr = curr->right;
            
        }
        
    }

};

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    sol.flateningTree(root);
    while(root!=NULL){
        cout<<root->data<<"->";
        root=root->right;
    }
    return 0;
}