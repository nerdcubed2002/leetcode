class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int i=0,j=n-1;
        vector<int> vt;
       while(i<=j)
       {
        if(numbers[i]+numbers[j]==target)
        break;
        else if(numbers[i]+numbers[j]>target)
        j--;
        else
        i++;
       }
       vt.push_back(i+1);
       vt.push_back(j+1);
       return vt;
    }
};