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
vector<int>postOrder(Node* root){
    vector<int>ans;
    stack<Node*>st1;
    stack<Node*>st2;
    if(root==NULL)return ans;
    st1.push(root);
    while(!st1.empty()){
        Node* dummy = st1.top();
        st2.push(st1.top());
        st1.pop();
        if(dummy->left){
            st1.push(dummy->left);
        }
        if(dummy->right){
            st1.push(dummy->right);
        }
    }
    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();

    }
    return ans;

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
    root->left->left->right = new Node(10);
    vector<int>ans = postOrder(root);
        for(int j=0;j<ans.size();j++){
            cout<<ans[j]<<" ";
        
        
    }


 return 0;
}