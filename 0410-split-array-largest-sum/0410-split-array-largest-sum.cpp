class Solution {
public:

int count(vector<int>& nums, int mid) {
    int n = nums.size();
    int cnt = 1;  // Start with 1 subarray (assuming all elements can fit into 1 initially)
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (sum + nums[i] <= mid) {
            sum += nums[i];  // Add element to current subarray if it fits
        } else {
            cnt++;  // If it doesn't fit, create a new subarray and add the element
            sum = nums[i];  // Start a new subarray with this element
        }
    }

    return cnt;
}

    int splitArray(vector<int>& nums, int k) {
        int n=nums.size(),lar=INT_MIN,sum=0,ans=-1;
        if(k>n)
        return ans;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            lar=max(lar,nums[i]);
        }

        int low=lar,high=sum;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(count(nums,mid)>k)
              {
                ans=mid;
                low=mid+1;
              }
              else
              high=mid-1;
        }
        return low;
    }
};