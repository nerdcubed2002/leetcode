class Solution {
public:

      int fp(int x,int y,int row,int col,vector<vector<int>>&dp)
    {
        if(x==col-1&&y==row-1)
        return 1;
        if(x==col||y==row)
        return 0;
        if(dp[y][x]!=-1)
        return dp[y][x];
        else
        return dp[y][x]=fp(x+1,y,row,col,dp)+fp(x,y+1,row,col,dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int cnt=fp(0,0,m,n,dp);
        return cnt;
    }

  

};