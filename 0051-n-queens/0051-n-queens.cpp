class Solution {
public:

    bool possible(int row,int col,vector<string>board,int n)
    {
        int r=row;
        int c=col;
        while(r>=0&&c>=0)
        {
            if(board[r][c]=='Q')
            return false;
            r--;
            c--;
        }
        r=row;
        c=col;
        while(c>=0)
        {
            if(board[r][c]=='Q')
            return false;
            c--;
        }
        r=row;
        c=col;
        while(r<n&&c>=0)
        {
            if(board[r][c]=='Q')
            return false;
            r++;
            c--;
        }

        return true;
    }
    void solve(int n,vector<string>&board,vector<vector<string>>&ans,int col)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++)
        {
            if(possible(row,col,board,n))
            {
                board[row][col]='Q';
                solve(n,board,ans,col+1);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n,string(n,'.'));
        solve(n,board,ans,0);
        return ans;
    }
};