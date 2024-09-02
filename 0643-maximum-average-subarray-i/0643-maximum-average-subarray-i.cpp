class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg=0;
        for(int i=0;i<k;i++)
        {
            avg+=nums[i];
        }
        double max_avg=avg;
        for(int i=1;i<=nums.size()-k;i++)
        {
            avg-=nums[i-1];
            avg+=nums[i+k-1];
            if(avg>max_avg)max_avg=avg;
        }
        return max_avg/k;
    }
};