class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int n=s.size(),j=0,max_len=INT_MIN,len=0;
        if(n==0)
        return 0;
        for(int i=0;i<n;i++)
        {
            if(st.find(s[i])==st.end())
            {
                st.insert(s[i]);
            }
            else
            {
                while(st.find(s[i])!=st.end())
                {
                   st.erase(s[j]);
                   j++;
                }
            }
            st.insert(s[i]);
            len=i-j+1;
            max_len=max(len,max_len);
        }

        return max_len;
    }
};