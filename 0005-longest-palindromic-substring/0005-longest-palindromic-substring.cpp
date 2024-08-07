class Solution {
public:
int t[1000][1000];
bool check(string&s,int i,int j)
{
    if(i>=j)
    return true;
    if(t[i][j]!=-1)
    return t[i][j];

    if(s[i]==s[j])
    return t[i][j]=check(s,i+1,j-1);

    return t[i][j]=0;
}
    string longestPalindrome(string s) {

       int n=s.length();
       int max_len=INT_MIN;
       int sp=0;
       memset(t,-1,sizeof(t));
       for(int i=0;i<n;i++)
       {
        for(int j=i;j<n;j++)
        {
            if(check(s,i,j)==true)
            {
                if(j-i+1>max_len)
                {
                    max_len=j-i+1;
                    sp=i;
                }
            }
        }
       } 

       return s.substr(sp,max_len);
    }
};