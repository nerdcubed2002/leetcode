class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int floor=-1,ceil=-1;
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                ceil=mid;
                low=mid+1;
            }
            else if(nums[mid]<target)
            {
               low=mid+1;
            }
            else
            {
                high=mid-1;
            }

        }

        low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                floor=mid;
                high=mid-1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return {floor,ceil};
    }
};