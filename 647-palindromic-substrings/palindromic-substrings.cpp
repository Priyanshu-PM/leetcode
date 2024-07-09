class Solution {
private:
    bool isPalindrome(string &s, int i, int j, vector<vector<int>>& dp)
    {
        if(i > j)   return 1;

        //  memoization
        if(dp[i][j] != -1)  return dp[i][j];

        if(s[i] == s[j])
        {
            return dp[i][j] = isPalindrome(s, i+1, j-1, dp);
        }
        return dp[i][j] = 0;
    }
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                if(isPalindrome(s, i, j, dp))    cnt++;
            }
        }
        return cnt;
        // vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int l = 1; l <= n; l++)
        {
            for(int i = 0; i + l - 1 < n; i++)
            {
                int j = i + l - 1;
                if(i == j)
                {
                    dp[i][j] = true;
                }
                else if(i+1 == j)
                {
                    if(s[i] == s[j])    dp[i][j] = true;
                }
                else
                {
                    if(s[i] == s[j] && dp[i+1][j-1] == true)
                    {
                        dp[i][j] = true;
                    }
                }
            }
        }
        // int cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
                if(dp[i][j])
                    cnt++;

        return cnt;
    }
};