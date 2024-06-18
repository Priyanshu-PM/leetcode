class Solution {

private:
    int solve(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp) {

        if(m == 0 && n == 0)    {
            return dp[m][n] = grid[m][n];
        }
        if(m < 0 || n < 0)      return INT_MAX;

        if(dp[m][n] != -1)  return dp[m][n];
        int up = INT_MAX;
        int left = INT_MAX;
        if(m > 0)   up = grid[m][n] + solve(grid, m-1, n, dp);
        if(n > 0)   left = grid[m][n] + solve(grid, m, n-1, dp);

        return dp[m][n] = min(up, left); 
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(grid, m-1, n-1, dp);
    }
};