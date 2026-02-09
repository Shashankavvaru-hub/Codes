class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        map<int,int>mpp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int sz = q.size();
            Node* curr = q.front().first;
            int col = q.front().second;
            q.pop();
            // For Bottom view remove this if condition update mpp[col] everytime
            if(!mpp.count(col)){
                mpp[col]=curr->data;
            }
            if(curr->left) q.push({curr->left,col-1});
            if(curr->right) q.push({curr->right,col+1});
        }
        for(auto &it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};