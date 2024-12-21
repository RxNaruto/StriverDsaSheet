#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};
vector<int>preOrderTraversal(Node* root){
    vector<int>preOrder;
    if(root==NULL)return preOrder;
    stack<Node*>st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        preOrder.push_back(root->data);
        if(root->right!=nullptr){
            st.push(root->right);
        }
        if(root->left!=nullptr){
            st.push(root->left);
        }
        
    }
    return preOrder;
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
    vector<int>ans = preOrderTraversal(root);
        for(int j=0;j<ans.size();j++){
            cout<<ans[j]<<" ";
        
        
    }


 return 0;
}