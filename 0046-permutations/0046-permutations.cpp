class Solution {
public:
    void pick(vector<int>&nums,vector<vector<int>>&ans,vector<int>per,int ind)
    {
        if(per.size()==nums.size())
        {
            ans.push_back(per);
            return;
        }
        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[i],nums[ind]);
            per.push_back(nums[ind]);
            pick(nums,ans,per,ind+1);
            swap(nums[i],nums[ind]);
            per.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>per;
        pick(nums,ans,per,0);
        return ans;
    }
};