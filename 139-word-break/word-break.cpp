class Solution {
private:
    int solve(int index, string &s, set<string>& st, vector<int>& dp)
    {
        if(index >= s.size())   return dp[index] = 1;

        if(dp[index] != -1) return dp[index];
        for(auto it: st)
        {
            int len = it.size();
            if(index + len <= s.size() && it == s.substr(index, len) && solve(index + len, s, st, dp))  return dp[index] = 1;
        }
        return dp[index] = 0;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        set<string> st;
        for(string str: wordDict)    st.insert(str);

        int n = s.size();
        vector<int> dp(n+1, -1);
        for(auto str: st)
        {
            int len = str.size();
            if(len <= s.size() && str == s.substr(0, len) && solve(len, s, st, dp)) return true;
        }
        return false;
    }
};