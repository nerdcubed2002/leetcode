class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double med;
        int i=0,j=0;
        int cnt=0;
        int m=nums1.size();
        int n=nums2.size();
        int size=m+n;
        vector<int>median(2,0);
        int k=0;
        if(m==1&&n==0)
        return nums1[0];
        if(n==1&&m==0)
        return nums2[0];

        while(i<m&&j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                cnt++;
                if(cnt>=size/2)
                {
                  median[k++]=nums1[i];
                  
                }
                i++;
                
            }
            else
            {
                
                cnt++;
                 if(cnt>=size/2)
                {
                  median[k++]=nums2[j];
                  
                }
                j++;
            }
            if(cnt==(size/2)+1)
            break;
            
        }

        while(i<m&&k<2)
        {
            cnt++;
                if(cnt>=size/2)
                {
                  median[k++]=nums1[i];
                  
                }
                i++;
        }

        while(j<n&&k<2)
        {
              cnt++;
                 if(cnt>=size/2)
                {
                  median[k++]=nums2[j];
                  
                }
                j++;
        }
        if(size%2==0)
        med=(median[0]+median[1])/2.0;
        else
        med=median[1];
        return med;
    }
};