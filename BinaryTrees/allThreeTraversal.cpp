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
void allThreeTraversal(Node* root){
    stack<pair<Node* , int>>st;
    st.push({root,1});
    vector<int>preOrder,postOrder,inorder;
    if(root==NULL)return;
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        if(it.second==1){
            preOrder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL){
                st.push({it.first->left,1});
            }

        }
        else if(it.second==2){
            inorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL){
                st.push({it.first->right,1});

            }

        }
        else{
            postOrder.push_back(it.first->data);
        }
    }
    cout<<"preorder: ";
    for(int i=0;i<preOrder.size();i++){
        cout<<preOrder[i]<<" ";
    }
    cout<<endl;
    cout<<"inorder: ";
    for(int i=0;i<inorder.size();i++){
        cout<<inorder[i]<<" ";
    }
    cout<<endl;
    cout<<"postorder: ";
    for(int i=0;i<postOrder.size();i++){
        cout<<postOrder[i]<<" ";
    }


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
    allThreeTraversal(root);
 return 0;
}