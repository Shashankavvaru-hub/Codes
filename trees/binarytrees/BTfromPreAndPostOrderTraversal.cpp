/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int>mpp;
    int idx=0;
    TreeNode* helper(vector<int>& preorder,int st,int end){
        if (st > end) return nullptr;
        TreeNode* node = new TreeNode(preorder[idx]);
        int mid = mpp[preorder[idx]];
        idx++;
        node->left=helper(preorder,st,mid-1);
        node->right = helper(preorder,mid+1,end);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        for(int i=0;i<n;i++){
            mpp[inorder[i]]=i;
        }
        return helper(preorder,0,n-1);
    }
};