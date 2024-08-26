class Solution {
public:
    void mark(vector<vector<char>>& board,int row,int col,int i,int j)
    {
        if(i==-1||i==row||j==-1||j==col||board[i][j]=='Y'||board[i][j]=='X')return;
        board[i][j]='Y';
        mark(board,row,col,i,j-1);
        mark(board,row,col,i,j+1);
        mark(board,row,col,i-1,j);
        mark(board,row,col,i+1,j);
    }
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<col;i++)
        if(board[0][i]=='O')mark(board,row,col,0,i);
        for(int i=0;i<col;i++)
        if(board[row-1][i]=='O')mark(board,row,col,row-1,i);
        for(int i=0;i<row;i++)
        if(board[i][0]=='O')mark(board,row,col,i,0);
        for(int i=0;i<row;i++)
        if(board[i][col-1]=='O')mark(board,row,col,i,col-1);

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]=='O')board[i][j]='X';
                if(board[i][j]=='Y')board[i][j]='O';
            }
        }
    }
};