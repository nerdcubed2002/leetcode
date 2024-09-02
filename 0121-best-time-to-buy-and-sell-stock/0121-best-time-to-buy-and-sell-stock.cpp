class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_p=0;
        int small=prices[0];
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<small)small=prices[i];
            else max_p=max(max_p,prices[i]-small);
        }
        return max_p;
    }
};