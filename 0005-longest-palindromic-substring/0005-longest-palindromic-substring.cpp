class Solution {
public:
bool check(string&s,int i,int j)
{
    if(i>=j)
    return true;

    if(s[i]==s[j])
    return check(s,i+1,j-1);

    return false;
}
    string longestPalindrome(string s) {

       int n=s.length();
       int max_len=INT_MIN;
       int sp=0;
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