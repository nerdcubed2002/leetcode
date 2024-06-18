class Solution {
public:
   void pick(vector<int>&candidates,vector<vector<int>>&ans,vector<int>&subset,int target,int i,int sum)
    {
         if(sum==target)
        {
           ans.push_back(subset);
           return;
        }
        if(i==candidates.size())
        return;
        if(sum>target)
        return;
       
        sum+=candidates[i];
        subset.push_back(candidates[i]);
        pick(candidates,ans,subset,target,i+1,sum);
        sum-=candidates[i];
        subset.pop_back();
        while(i+1<candidates.size()&&candidates[i]==candidates[i+1])
        i++;
        pick(candidates,ans,subset,target,i+1,sum);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>subset;
        sort(candidates.begin(),candidates.end());
        pick(candidates,ans,subset,target,0,0);
        return ans;
    }
};