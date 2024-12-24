#include<iostream>
#include <string>
#include <sstream>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data = val;
        right = left = NULL;
    }
};
string serialize(Node* root){
    queue<Node*>q;
    string s=" ";
    if(root==NULL)return " ";
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr==NULL)s.append("#,");
        else s.append(to_string(curr->data)+',');

        if(curr!=NULL){
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return s;
    
}
Node* deserialize(string data){
    if(data.size()==0)return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    Node* root = new Node(stoi(str));
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        getline(s,str,',');
        if(str=="#")curr->left =NULL;
        else {
            Node* leftNode = new Node(stoi(str));
            curr->left = leftNode;
            q.push(leftNode);
        }
        getline(s,str,',');
        if(str=="#")curr->right =NULL;
        else {
            Node* rightNode = new Node(stoi(str));
            curr->right = rightNode;
            q.push(rightNode);
        }


    }
    return root;
}
void inOrderrr(Node* root){
    if(root==NULL)return;
    inOrderrr(root->left);
    cout<<root->data<<" ";
    inOrderrr(root->right);
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    cout<<serialize(root);
    string s = serialize(root);
    Node* nRoot = deserialize(s);
    cout<<endl;
    inOrderrr(nRoot);




 return 0;
}