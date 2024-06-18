class Solution {
public:
    void pick(vector<int>&candidates,vector<vector<int>>&ans,vector<int>&subset,int i,int target,int sum)
    {
        if(i==candidates.size())
        return;
        else if(sum>target)
        return;
        else if(sum==target)
        {
            ans.push_back(subset);
            return;
        }

        sum+=candidates[i];
        subset.push_back(candidates[i]);
        pick(candidates,ans,subset,i,target,sum);
        sum-=candidates[i];
        subset.pop_back();
        pick(candidates,ans,subset,i+1,target,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>subset;
        pick(candidates,ans,subset,0,target,0);
        return ans;

    }
};