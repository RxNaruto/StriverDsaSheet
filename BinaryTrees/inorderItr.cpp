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
vector<int>inorder(Node* root){
    vector<int>ans;
    stack<Node*>st;
    Node* dummy = root;
    while(true){
        if(dummy!=NULL){
            st.push(dummy);
            dummy=dummy->left;
        }
        else{
            if(st.empty()){
                 break;
            }
            dummy = st.top();
            st.pop();
            ans.push_back(dummy->data);
            dummy=dummy->right;

        }
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
    vector<int>ans = inorder(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    


 return 0;
}