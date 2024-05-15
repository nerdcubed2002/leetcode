class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int j=0,cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            j=i+1;
            else
            cnt=max(cnt,i-j+1);


        }

        return cnt;
    }
};