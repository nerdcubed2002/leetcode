class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int low=0,high=nums.size()-1;
        sort(nums.begin(),nums.end());
        int cnt=0;
        while(low<high)
        {
            if(nums[low]+nums[high]==k)
            {
                low++;
                high--;
                cnt++;
            }
            else if(nums[low]+nums[high]>k)
            high--;
            else
            low++;
        }
        return cnt;
    }
};