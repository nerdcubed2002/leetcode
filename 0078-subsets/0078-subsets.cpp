class Solution {
public:

    void select(vector<int>&nums,int i,vector<int>&subset,vector<vector<int>>&ans)
    {
        if(i==nums.size())
        {
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        select(nums,i+1,subset,ans);
        subset.pop_back();
        select(nums,i+1,subset,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subset;
        vector<vector<int>>ans;
        select(nums,0,subset,ans);
        return ans;
    }

};