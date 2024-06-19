class Solution {
public:

    void find(vector<int>&temp,string&ans,int k)
    {
        if(temp.size()==0)
        return;
        int fact=1;
        int n=temp.size();
        for(int i=1;i<n;i++)
        fact=fact*i;
        ans+=to_string(temp[k/fact]);
        temp.erase(temp.begin()+k/fact);
        find(temp,ans,k%fact);

    }
    string getPermutation(int n, int k) {
        vector<int>temp;
        for(int i=1;i<=n;i++)
        temp.push_back(i);
        string ans="";
        find(temp,ans,k-1);
        return ans;
    }
};