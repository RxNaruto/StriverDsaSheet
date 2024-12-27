#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data= val;
        right= left = NULL;
    }
};
class BstIterator{
    private:
    stack<Node*>st;
    void pushAll(Node* root){
        for(;root!=NULL;st.push(root),root=root->left);
    }

    public:
    BstIterator(Node* root){
        pushAll(root);
    }
    bool hasNext(){
        return !st.empty();
    }
    int next(){
        Node* root = st.top();
        st.pop();
        pushAll(root->right);
        return root->data;

    }
    
};
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

    BstIterator sol(root);
    cout<<sol.next()<<endl;
    cout<<sol.hasNext();


 return 0;
}