class Solution {
public:
    int dp[20001][201];
    int find(vector<int>&nums,int target,int index)
    {
        if(target==0)return 1;
        if(nums.size()==index||target<0)return 0;
        if(dp[target][index]!=-1)return dp[target][index];
        int take=find(nums,target-nums[index],index+1);
        int ntake=find(nums,target,index+1);
        return dp[target][index]=take||ntake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto el:nums)sum+=el;
        if(sum%2!=0)return false;
        memset(dp,-1,sizeof(dp));
        return find(nums,sum/2,0);
    }
};