#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        right = left = NULL;
    }
};

int findDiameter(Node* root, int& maxH) {
    if (root == NULL) return 0;

    int lh = findDiameter(root->left, maxH);
    int rh = findDiameter(root->right, maxH);

    // Update the maximum diameter
    maxH = max(maxH, lh + rh);

    // Return the height of the subtree
    return 1 + max(lh, rh);
}

int diameter(Node* root) {
    int maxH = 0; // Initialize maxH to track the maximum diameter
    findDiameter(root, maxH);
    return maxH; // Return the maximum diameter
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    root->right->left = new Node(6);

    cout << diameter(root);
    return 0;
}
