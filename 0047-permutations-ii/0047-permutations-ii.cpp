class Solution {
public:
    void pick(vector<int>&nums,vector<vector<int>>&ans,vector<int>&per,int ind)
    {
        if(per.size()==nums.size())
        {
            ans.push_back(per);
            return;
        }
        unordered_set<int>m;

        for(int i=ind;i<nums.size();i++)
        {  if(m.find(nums[i])!=m.end())continue;
            m.insert(nums[i]);
           swap(nums[ind],nums[i]);
           per.push_back(nums[ind]);
           pick(nums,ans,per,ind+1);
           swap(nums[i],nums[ind]);
           per.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>per;
        sort(nums.begin(),nums.end());
        pick(nums,ans,per,0);
        return ans;
    }
};