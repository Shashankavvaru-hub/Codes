// using hashmap 

example: [1,2,3], k=3
prefSum: 1, 3, 6
remove: -2, 0, 3
mpp: {0,1}, {1,1}, {3,1}, {6,1}
cnt: 0, 1, 2

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0]=1;  // {0,1} - {prefSum,Freq}
        int n=nums.size(),prefSum=0,cnt=0;
        for(int i=0;i<n;i++){
            prefSum+=nums[i];
            int remove = prefSum - k;
            cnt+=mpp[remove];
            mpp[prefSum]++;
        }
        return cnt;
    }
};