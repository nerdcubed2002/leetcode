class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // Skip duplicate values for i

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1])
                        j++; // Skip duplicate values for j
                    while (j < k && nums[k] == nums[k - 1])
                        k--; // Skip duplicate values for k
                    j++;
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return ret;
    }
};
