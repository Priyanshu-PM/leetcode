class Solution {
private:
    int solve(int i, int j, string s, string t, vector<vector<int>>& dp)
    {
        if(i < 0)   return j+1;
        if(j < 0)   return i+1;

        if(dp[i][j] != -1)  return dp[i][j];

        // if they character match, don't apply any steps
        if(s[i] == t[j])
            return dp[i][j] =  0 + solve(i-1, j-1, s, t, dp);
        else
        {
            int insertion = 1 + solve(i, j-1, s, t, dp);
            int deletion = 1 + solve(i-1, j, s, t, dp);
            int replace = 1 + solve(i-1, j-1, s, t, dp);

            return dp[i][j] = min(insertion, min(deletion, replace));
        }
    }

public:
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();

        if(n == 0 || m == 0)
            return max(n, m);

        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return solve(n-1, m-1, word1, word2, dp);
        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // base cases
        // for(int i = 0; i <= n; i++)
        //     dp[i][0] = i;
        
        // for(int j = 0; j <= m; j++)
        //     dp[0][j] = j;

        vector<int> prev(m+1, 0), curr(m+1, 0);

        for(int j = 0; j <= m; j++)
            prev[j] = j;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                curr[0] = i;
                if(word1[i-1] == word2[j-1])
                    curr[j] = prev[j-1];
                else
                {
                    int insertion = 1 + curr[j-1];
                    int deletion = 1 + prev[j];
                    int replace = 1 + prev[j-1];

                    curr[j] = min(insertion, min(deletion, replace));
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};