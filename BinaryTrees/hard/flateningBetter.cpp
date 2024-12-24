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
        stack<Node*>st;
        if(root==NULL)return;
        st.push(root);
        while(!st.empty()){
            Node* curr = st.top();
            st.pop();
            if(curr->right)st.push(curr->right);
            if(curr->left)st.push(curr->left);
            if(!st.empty()){
                curr->right = st.top();

            }
            curr->left = NULL;
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