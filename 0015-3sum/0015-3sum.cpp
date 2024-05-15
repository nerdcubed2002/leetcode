class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=0;
        vector<vector<int>>vt;
        for(int i=0;i<n-2;i++)
        {if(i>0&&nums[i-1]==nums[i])
        continue;
            int j=i+1,k=n-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0)
                k--;
                else if(sum<0)
                j++;
                else
                {
                    vt.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(nums[j-1]==nums[j]&&j<k)
                    j++;
                    while(nums[k]==nums[k+1]&&j<k)
                    k--;
                }
            }
        }
        return vt;
    }
};