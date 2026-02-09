/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// BFS Solutions
class Solution {
    unordered_map<TreeNode*,TreeNode*>parent;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0) return {target->val};
        findParents(root);
        vector<int>res;
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>visited;
        q.push(target);
        visited[target]=true;
        int distance=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* t=q.front();
                q.pop();
                if(t->left && !visited[t->left]){
                    q.push(t->left);
                    visited[t->left]=true;
                }
                if(t->right && !visited[t->right]){
                    q.push(t->right);
                    visited[t->right]=true;
                }
                if(parent[t] && !visited[parent[t]]){
                    q.push(parent[t]);
                    visited[parent[t]]=true;
                }
            }
            distance++;
            if(distance==k){
                break;
            }
        }
        while(!q.empty()){
          res.push_back(q.front()->val);
          q.pop();
        }
        return res;
    }
    void findParents(TreeNode* root){
        if(!root) return;
        if(root->left){
            parent[root->left]=root;
            findParents(root->left);
        }
        if(root->right){
            parent[root->right]=root;
            findParents(root->right);
        }
    }
};

//DFS Solution

class Solution {
public:
    unordered_set<TreeNode*>vis;
    unordered_map<TreeNode*, TreeNode*>par;
    vector<int>res;
    void dfs(TreeNode* root,int dist,int k){
        if(!root) return;
        if(vis.count(root)) return;
        if(dist==k){
            res.push_back(root->val);
            return;
        }
        vis.insert(root);
        dfs(root->left,dist+1,k);
        dfs(root->right,dist+1,k);
    }
    void findParents(TreeNode* root,TreeNode* parentNode){
        if(!root) return;
        par[root]=parentNode;
        findParents(root->left,root);
        findParents(root->right,root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findParents(root,nullptr);
        root=target;
        for(int i=0;i<=k;i++){
            dfs(root,i,k);
            root=par[root];
            if(!root) break;
        }
        return res;
    }
};