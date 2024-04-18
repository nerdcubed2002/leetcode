class Solution {
public:
bool ship(vector<int>& weights, int days,int mid)
{
    int cnt=1;
    int i=0,n=weights.size();
    while(cnt<=days)
    {
        int sum=0;
        while(i<n)
        {
            sum+=weights[i];
            if(sum<=mid)
            i++;
            else
            break;
        }
        cnt++;
    }
    if(i==n)
    return true;
    return false;

    

}
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0,n=weights.size();
        for(int i=0;i<n;i++)
        sum+=weights[i];
        int low=1,high=sum;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(ship(weights,days,mid)==true)
            high=mid-1;
            else
            low=mid+1;
        }
        return low;
        
    }
};