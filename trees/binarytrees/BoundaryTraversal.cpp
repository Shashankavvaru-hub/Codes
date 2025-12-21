#include<bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
class Solution {
  public:
    bool isLeaf(Node* root){
        return !root->left && !root->right;
    }
    void addLeftBoundary(Node* root,vector<int>&res){
        Node* curr=root->left;
        while(curr){
            if(!isLeaf(curr)) res.push_back(curr->data);
            if(curr->left) curr=curr->left;
            else curr=curr->right;
        }
    }
    
    // just like DFS Traversal
    void addLeafNodes(Node* root,vector<int>&res){
        if (!root) return;
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        addLeafNodes(root->left,res);
        addLeafNodes(root->right,res);
    }
    void addRightBoundary(Node* root,vector<int>&res){
        Node* curr=root->right;
        vector<int>temp;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right) curr=curr->right;
            else curr=curr->left;
        }
        int sz=temp.size();
        for(int i=sz-1;i>=0;i--) res.push_back(temp[i]);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        if(!root) return {};
        vector<int>res;
        // If the root is a leaf, it will be added in addLeafNodes().
        if (!isLeaf(root)) res.push_back(root->data);
        addLeftBoundary(root,res);
        addLeafNodes(root,res);
        addRightBoundary(root,res);
        return res;
    }
};