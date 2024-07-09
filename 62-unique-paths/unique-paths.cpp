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
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        // return (int)countPaths(m-1, n-1, dp);

        // Time Complextiy = m x n
        // Space Complexity = m x n

        // tabulation method
        dp[0][0] = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0)    dp[i][j] = 1;
                else {
                    int bottom = 0, right = 0;
                    if(i > 0)   bottom = dp[i-1][j];
                    if(j > 0)   right = dp[i][j-1];

                    dp[i][j] = bottom + right;
                }
            }
        }

        return dp[m-1][n-1];

    }
};