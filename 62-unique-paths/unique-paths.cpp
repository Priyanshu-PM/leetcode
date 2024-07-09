// #define mod 1e9+10
typedef long long int ll;

class Solution {
// private:
//     ll countPaths(int m, int n, vector<vector<int>>& dp) {

//         if(m == 0 && n == 0)    return dp[m][n] = 1;
//         if(m < 0 || n < 0) return 0;

//         // memoization
//         if(dp[m][n] != -1)  return dp[m][n];
        
//         ll countLeft = countPaths(m-1, n, dp);
//         ll countUp = countPaths(m, n-1, dp);
//         return dp[m][n] = countLeft + countUp;
//     }

public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)    dp[i][j] = 1;
                else {
                    int top = 0, left = 0;
                    if(i > 0)   top = dp[i-1][j];
                    if(j > 0 )  left = dp[i][j-1];

                    dp[i][j] = top + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};