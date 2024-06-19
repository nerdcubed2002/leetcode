class Solution {
public:

   bool ispalindrome(string x)
   {
     string t=x;
     reverse(t.begin(),t.end());
     return t==x;
   }

    void fnc(string s,vector<string>&v,vector<vector<string>>&ans)
    {
        if(s.size()==0)
        {
            ans.push_back(v);
            return;
        }

        for(int len=1;len<=s.size();len++)
        {
           string x= s.substr(0,len);
            if(ispalindrome(x))
            {
                v.push_back(x);
                string y=s.substr(len,s.size()-len);
                fnc(y,v,ans);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
       vector<vector<string>>ans;
       vector<string>v;
       fnc(s,v,ans); 
       return ans;
    }

};