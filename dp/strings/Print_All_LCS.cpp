class Solution {
  public:
    set<string> dfs(int i,int j,string &s1,string &s2,vector<vector<int>>&dp,vector<vector<bool>>&vis,vector<vector<set<string>>>&memo){
        if(dp[i][j]==0)  return {""};
        if(vis[i][j]) return memo[i][j];
        vis[i][j] = true;
        set<string>res;
        if(s1[i-1]==s2[j-1]){
            set<string> prev = dfs(i-1,j-1,s1,s2,dp,vis,memo);
            for(auto &str:prev){
                res.insert(str + s1[i-1]);
            }
        }
        if(dp[i-1][j]==dp[i][j]){
            res.merge(dfs(i-1,j,s1,s2,dp,vis,memo)); 
        }
        if(dp[i][j-1]==dp[i][j]){
            res.merge(dfs(i,j-1,s1,s2,dp,vis,memo));
        }
        return memo[i][j]=res;
    }
    vector<string> allLCS(string &s1, string &s2) {
        // Code here
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    int movei = dp[i-1][j];
                    int movej = dp[i][j-1];
                    dp[i][j]=max(movei,movej);
                }
            }
        }
        vector<vector<bool>>vis(n+1,vector<bool>(m+1,false));
        vector<vector<set<string>>>memo(n+1,vector<set<string>>(m+1));
        set<string> res = dfs(n, m, s1, s2, dp, vis, memo);
        vector<string>v(res.begin(),res.end());
        return v;
    }
};
