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
    map<int, vector<pair<int,int>>> mpp;
    void dfs(TreeNode* root,int row,int col){
        if(!root) return;
        mpp[col].push_back({row, root->val});
        dfs(root->left,row+1,col-1);
        dfs(root->right,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        vector<vector<int>>ans;
        for(auto &it:mpp){
            auto &vec = it.second;
            sort(vec.begin(),vec.end());
            vector<int>cols;
            for(auto &p:vec){
                cols.push_back(p.second);
            }
            ans.push_back(cols);
        }
        return ans;
    }
};