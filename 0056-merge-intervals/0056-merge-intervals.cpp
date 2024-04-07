class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size(),j=0;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ret={intervals[0]};
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<=ret[j][1])
            {
                if(intervals[i][1]>ret[j][1])
                ret[j][1]=intervals[i][1];
            }
            else
            {
                ret.push_back(intervals[i]);
                j++;
            }
        }
        return ret;
    }
};