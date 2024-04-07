class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        int maj_1 = INT_MIN, maj_2 = INT_MIN, cnt_1 = 0, cnt_2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == maj_1)
                cnt_1++;
            else if (nums[i] == maj_2)
                cnt_2++;
            else if (cnt_1 == 0) {
                maj_1 = nums[i];
                cnt_1 = 1;
            } else if (cnt_2 == 0) {
                maj_2 = nums[i];
                cnt_2 = 1;
            } else {
                cnt_1--;
                cnt_2--;
            }
        }

        cnt_1 = 0;
        cnt_2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == maj_1)
                cnt_1++;
            else if (nums[i] == maj_2)
                cnt_2++;
        }

        if (cnt_1 > n / 3)
            ret.push_back(maj_1);
        if (cnt_2 > n / 3 && maj_1 != maj_2)
            ret.push_back(maj_2);

        return ret;
    }
};
