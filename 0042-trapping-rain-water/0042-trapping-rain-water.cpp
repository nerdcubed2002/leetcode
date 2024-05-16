class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=1,r=n-2,water=0;
        int maxleft=height[0],maxright=height[n-1];
        while(l<=r)
        {
            if(maxleft<maxright)
            {
                if(height[l]>maxleft)
                maxleft=height[l];
                else
                water+=maxleft-height[l];
                l++;
            }
            else
            {
                if(height[r]>maxright)
                maxright=height[r];
                else
                water+=maxright-height[r];
                r--;
            }
        }

        return water;
    }
};