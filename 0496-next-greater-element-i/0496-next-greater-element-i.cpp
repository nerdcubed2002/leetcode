class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp;
        vector<int>ans(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++)
        {
            mp[nums1[i]]=i;
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(mp.find(nums2[i])!=mp.end())
            {
                int j=i+1;
                for(;j<nums2.size();j++)
                {
                    if(nums2[j]>nums2[i])
                    {
                        ans[mp[nums2[i]]]=nums2[j];
                        break;
                    }
                }
            
            }
        }
      return ans;
    }
};