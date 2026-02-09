
// Counts subarrays with sum exactly equal to goal by subtracting the number of subarrays with sum ≤ goal−1 from those with sum ≤ goal, using a sliding window.
class Solution {
public:
    int lessEqualsToK(vector<int>&nums,int goal){
        if(goal<0) return 0;
        int l=0,r=0,n=nums.size(),ans=0,sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l++];
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return lessEqualsToK(nums,goal) - lessEqualsToK(nums,goal-1);
    }
};