class Solution {
public:

    int bs(vector<int>& nums,int low,int high,int k)
    {
        if(low>high)
        return -1;
        int mid=(low+high)/2;
        if(nums[mid]==k)
        return mid;
        else if(k<nums[mid])
        return bs(nums,low,mid-1,k);
        else
        return bs(nums,mid+1,high,k);
    }    
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return bs(nums,0,n-1,target);
        
    }
};