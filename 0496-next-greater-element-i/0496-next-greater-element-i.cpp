class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp;
        for(int i=0;i<nums1.size();i++)
        {
            mp[nums1[i]]=i;
        }
        vector<int>ans(nums1.size(),-1);
        stack<int>st;
        for(int j=0;j<nums2.size();j++)
        {
            while(!st.empty()&&nums2[j]>st.top())
            {
                int el=st.top();
                st.pop();
                ans[mp[el]]=nums2[j];
            }
            if(mp.find(nums2[j])!=mp.end())
            {
                st.push(nums2[j]);
            }
        }

        return ans;
    }
};