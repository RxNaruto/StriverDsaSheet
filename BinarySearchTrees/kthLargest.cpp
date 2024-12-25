#include <iostream>
#include <utility>
using namespace std;
struct Node
{
    int data;
    Node *right;
    Node *left;

    Node(int val)
    {
        data = val;
        right = left = NULL;
    }
};
class Solution
{
private:
    
    void kthLargest(Node *root, int k,int& cnt,int &kthLarg )
    {
        if (!root || cnt >= k)
            return;
        kthLargest(root->left, k,cnt,kthLarg);
        cnt++;
        if (cnt == k)
        {
            kthLarg = root->data;
            return;
        }
        kthLargest(root->right, k,cnt,kthLarg);
    }
    void kthSmallest(Node* root,int k,int& cnt,int& kthSmall){
        if (!root || cnt >= k)
            return;
        kthSmallest(root->right,k,cnt,kthSmall);
        cnt++;
        if(cnt==k){
            kthSmall = root->data;
            return;
        }
        kthSmallest(root->left,k,cnt,kthSmall);

    }
    public:

    pair<int,int> kthLargSmall(Node* root,int k){
        int kSmall=INT_MAX;
        int kLarge= INT_MIN;
        int cnt = 0;

        kthLargest(root,k,cnt,kLarge);
        cnt = 0;
        kthSmallest(root,k,cnt,kSmall);
        return make_pair(kSmall, kLarge);
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
    Solution solution;

   
    int k = 1; 
    cout << "k: "<< k <<endl;
    pair<int, int> kthElements = solution.kthLargSmall(root, k);

    cout << "Kth smallest element: " << kthElements.second << endl;
    cout << "Kth largest element: " << kthElements.first << endl;

    
    return 0;
}