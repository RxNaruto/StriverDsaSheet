#include<iostream>
#include<stack>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data=val;
        right = left = NULL;
    }
};
class BstIterator{
    private:
    stack<Node*>st;
    bool reverse = true;
    //reverse -> true -> before
    //reverse -> false -> next
    void pushAll(Node* root){
        for(;root!=NULL;){
            st.push(root);
            if(reverse==true){
                root = root->right;
            }
            else{
                root= root->left;
            }
        }
    }

    public:
    BstIterator(Node* root,bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    bool hasNext(){
        return !st.empty();
    }
    int next(){
        Node* root = st.top();
        st.pop();
        if(!reverse)pushAll(root->right);
        else pushAll(root->left);
        return root->data;
    }


};
class Solution{
    public:

    bool findTarget(Node* root,int k){
        if(root==NULL)return false;
        //next
        BstIterator l(root,false);
        BstIterator r(root,true);

        int i = l.next();
        int j = r.next();

        while(i<j){
            if(i+j==k){
                return true;
            }
            else if(i+j<k ){
                i=l.next();
            }
            else{
                j=r.next();
            }
        }
        return false;


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

    Solution sol;
    cout<<sol.findTarget(root,160);
 return 0;
}