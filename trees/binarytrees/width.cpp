/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        int res = 1;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int sz = q.size();
            long long minIdx = q.front().second;
            int first, last;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front().first;
                long long currIdx = q.front().second - minIdx;
                q.pop();
                if (i == 0)
                    first = currIdx;
                if (i == sz - 1)
                    last = currIdx;
                if (node->left)
                    q.push({node->left, 2 * currIdx + 1});
                if (node->right)
                    q.push({node->right, 2 * currIdx + 2});
            }
            res = max(res, last - first + 1);
        }
        return res;
    }
};