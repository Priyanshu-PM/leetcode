typedef long long int ll;
#define mod 1e9+7

class Solution {
private:

    ll findUniquePaths(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<ll>>& dp) {

        if(i == 0 && j == 0)    return dp[i][j] = 1;
        if(i < 0 || j < 0)      return 0;

        if(dp[i][j] != -1)      return dp[i][j];

        ll up = 0;
        if(i-1 >= 0 && obstacleGrid[i-1][j] != 1)
            up = findUniquePaths(obstacleGrid, i-1, j, dp);

        ll left = 0;
        if(j-1 >= 0 && obstacleGrid[i][j-1] != 1)
            left = findUniquePaths(obstacleGrid, i, j-1, dp);

        return dp[i][j] = up + left; 
    }


public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<ll>> dp(m, vector<ll>(n, 0));
        
        if(obstacleGrid[m-1][n-1] == 1) return 0;
        if(obstacleGrid[0][0] == 1)    return 0;

        dp[0][0] = 1;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1)    continue;
                int left = 0, up = 0;
        
                if(i > 0)    up = dp[i-1][j];
                if(j > 0)    left = dp[i][j-1];    
                    
                dp[i][j] = dp[i][j] + left + up;
            }
        }
        return dp[m-1][n-1];
    }
};