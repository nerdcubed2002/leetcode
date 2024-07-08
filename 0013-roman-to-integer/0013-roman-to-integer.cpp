class Solution {
public:
    int romanToInt(string s) {
        map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int n=s.size();
        int i=0;
        int sum=0;
        while(i<n)
        {
            if(i+1<n && mp[s[i]]<mp[s[i+1]])
            {
                sum+=mp[s[i+1]]-mp[s[i]];
                i+=2;
            }
            else
            {
               sum+=mp[s[i]];
               i++;
            }
         }
        return sum;
    }
};