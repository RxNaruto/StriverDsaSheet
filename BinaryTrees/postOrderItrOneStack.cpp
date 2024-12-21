#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

vector<int> postOrder(Node* root) {
    stack<Node*> st;
    vector<int> ans;
    Node* curr = root;

    while (curr != NULL || !st.empty()) {
        if (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        } else {
            Node* temp = st.top()->right;
            if (temp == NULL) {
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            } else {
                curr = temp;
            }
        }
    }
    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = postOrder(root);
    for (int j = 0; j < ans.size(); j++) {
        cout << ans[j] << " ";
    }

    return 0;
}
