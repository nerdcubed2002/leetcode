class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return answer(nums, 0, n - 1);
    }
    int answer(vector<int>& nums, int low, int high) {
    if (low == high) {
        return 0;
    }
    
    int mid = (low + high) / 2;
    int x = answer(nums, low, mid);
    int y = answer(nums, mid + 1, high);
    
    // Add inversion counting logic here
    int i = low, j = mid + 1;
    int pairs = 0;
    while (i <= mid && j <= high) {
        long x=nums[i],y=nums[j];
        if (x > 2*y) {
            pairs += mid - i + 1;
            j++;
        } else {
            i++;
        }
    }
    
    // Merge step
    i = low, j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= high) {
        if (nums[i] < nums[j]) {
            temp.push_back(nums[i]);
            i++;
        } else {
            temp.push_back(nums[j]);
            j++;
        }
    }
    
    while (i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }
    
    while (j <= high) {
        temp.push_back(nums[j]);
        j++;
    }
    
    for (int k = 0; k < temp.size(); k++) {
        nums[low + k] = temp[k];
    }
    
    return x + y + pairs;
}



};