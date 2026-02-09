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
    bool isExists(int idx, TreeNode* root, int h) {
        int mask = 1 << (h - 1);
        while (mask > 0 && root) {
            if (mask & idx) {
                root = root->right;
            } else {
                root = root->left;
            }
            mask >>= 1;
        }
        return root != nullptr;
    }
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        TreeNode* temp = root;
        int height = 0;
        while (temp->left) {
            temp = temp->left;
            height++;
        }
        if (height == 0)
            return 1;
        int low = 0, high = (1 << height) - 1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (isExists(mid, root, height)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return (1 << height) - 1 + low;
    }
};