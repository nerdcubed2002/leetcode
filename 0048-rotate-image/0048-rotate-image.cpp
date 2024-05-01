class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int m=matrix.size();
       int n=matrix[0].size();
       for(int i=0;i<m;i++)
       for(int j=i;j<n;j++)
       {
          swap(matrix[i][j],matrix[j][i]);
       } 
       for(int i=0;i<n/2;i++)
       for(int j=0;j<m;j++)
       {
        swap(matrix[j][i],matrix[j][n-1-i]);
       }


    }
};