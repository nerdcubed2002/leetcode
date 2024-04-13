class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        int x=nums[0],ans=n;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>=x)
            low=mid+1;
            else
            {
                ans=min(ans,mid);
                high=mid-1;
            }

        }
        low=0,high=ans-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            return mid;
            else if(nums[mid]>target)
            high=mid-1;
            else
            low=mid+1;
        }

         low=ans,high=n-1;
        while(low<=high)
        {
             int mid=(low+high)/2;
            if(nums[mid]==target)
            return mid;
            else if(nums[mid]>target)
            high=mid-1;
            else
            low=mid+1;
        }
        return -1;


    }
};