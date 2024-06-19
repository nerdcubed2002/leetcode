class Solution {
public:
    void pick(vector<int>&nums,vector<vector<int>>&ans,vector<int>&per,int f[])
    {
        if(per.size()==nums.size())
        {
            ans.push_back(per);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(!f[i])
            {
                f[i]=1;
                per.push_back(nums[i]);
                pick(nums,ans,per,f);
                per.pop_back();
                f[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>per;
        int f[nums.size()];
        for(int i=0;i<nums.size();i++)
        f[i]=0;
        pick(nums,ans,per,f);
        return ans;
    }
};