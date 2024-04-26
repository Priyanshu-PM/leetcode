class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& grid, int n, vector<vector<int>>& dp)
    {
        if(col < 0 || col >= n)
            return 1e8;

        if(row == 0)
        {
            return dp[row][col] = grid[0][col];
        }

        if(dp[row][col] != -1)
            return dp[row][col];

        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(col != i)
            {
                ans = min(ans, grid[row][col] + solve(row - 1, i, grid, n, dp));
            }
        }

        return dp[row][col] = ans;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int len = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(len, vector<int>(n, -1));
        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            ans = min(ans, solve(len - 1, i, grid, n, dp));
        }
        return ans;
    }
};