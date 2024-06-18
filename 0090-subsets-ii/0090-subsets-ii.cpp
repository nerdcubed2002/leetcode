class Solution {
public:
    void pick(int i,vector<int>&nums,vector<vector<int>>&ans,vector<int>&subset)
    {
        if(i==nums.size())
        {
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        pick(i+1,nums,ans,subset);
        subset.pop_back();
        while(i+1<nums.size()&&nums[i]==nums[i+1])
        i++;
        pick(i+1,nums,ans,subset);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>subset;
        sort(nums.begin(),nums.end());
        pick(0,nums,ans,subset);
        return ans;
        
    }
};