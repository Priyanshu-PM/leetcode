class Solution {
private:
    int solve(int i, int j, string pattern, string text, vector<vector<int>>& dp)
    {
        //  base cases
        if(i >= pattern.size() && j >= text.size())    return 1;
        if(i >= pattern.size() && j < text.size())  return 0;

        //  memoization
        if(dp[i][j] != -1)  return dp[i][j];

        //  checking if the current character matches or the pattern is '.'
        bool same = j < text.size() && (text[j] == pattern[i] || pattern[i] == '.');

        if(i + 1 < pattern.size() && pattern[i+1] == '*')
        {
            //  for matching zero occurences and matching current character
            return dp[i][j] = solve(i+2, j, pattern, text, dp) | (same && solve(i, j+1, pattern, text, dp));
        }
        if(same)
        {
            //  characters matched, hence moving to the next string
            return dp[i][j] = solve(i+1, j+1, pattern, text, dp);
        }
        else
            return dp[i][j] = 0;
    }

public:
    bool isMatch(string text, string pattern) {
        
        if(text == pattern) return true;
        int n = pattern.size();
        int m = text.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(0, 0, pattern, text, dp);
    }
};