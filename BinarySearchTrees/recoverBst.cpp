#include<iostream>
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int x){
        val = x;
        right=left = NULL;
    }
};
class Solution {
    private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;

    
public:
    void inorder(TreeNode* root){
        if(root==NULL)return;
        inorder(root->left);
        if(prev!=NULL && prev->val>root->val){
            if(first==NULL){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last){
            swap(first->val,last->val);

        }
        else if(first && middle){
            swap(first->val,middle->val);
        }
        
    }
};
void inorder(TreeNode* root){
    if(root==NULL)return;
    cout<<root->val;
    inorder(root->left);
    inorder(root->right);
}
int main()
{
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(10);
    root->right->left = new TreeNode(2);
    inorder(root);
    cout<<endl;
    Solution sol;
    sol.recoverTree(root);
    inorder(root);
 return 0;
}