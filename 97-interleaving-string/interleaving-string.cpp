class Solution {
public:
    int solve(int ind1, int ind2, int ind, string &s1, string &s2, string &s3, vector<vector<vector<int>>>& dp)
    {
        //  base cases
        if(ind1 >= s1.size() && ind2 >= s2.size()) {
            if(ind >= s3.size()) return 1;
            return 0;
        }

        if(ind1 > s1.size() || ind2 > s2.size())    return 0;

        if(dp[ind1][ind2][ind] != -1)
            return dp[ind1][ind2][ind];
        
        if(s1[ind1] == s3[ind] && s2[ind2] == s3[ind]) {
            return dp[ind1][ind2][ind] = (solve(ind1 + 1, ind2, ind + 1, s1, s2, s3, dp) 
             | solve(ind1, ind2 + 1, ind + 1, s1, s2, s3, dp));
        }

        if(s1[ind1] == s3[ind])
            return dp[ind1][ind2][ind] = solve(ind1 + 1, ind2, ind + 1, s1, s2, s3, dp);
        
        if(s2[ind2] == s3[ind])
            return dp[ind1][ind2][ind] = solve(ind1, ind2 + 1, ind + 1, s1, s2, s3, dp);
        
        return dp[ind1][ind2][ind] = 0;
    }

    bool isInterleave(string s1, string s2, string s3) {
        
        int n = s1.size();
        int m = s2.size();
        int t = s3.size();

        if(n+m != t)    return false;

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(t+1, -1)));

        return solve(0, 0, 0, s1, s2, s3, dp);
    }
};