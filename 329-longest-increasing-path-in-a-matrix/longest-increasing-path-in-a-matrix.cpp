class Solution {
private:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        if(dp[i][j] != -1)  return dp[i][j];    //  memoization

        int left = 0, right = 0, bottom = 0, top = 0;
        if(j-1 >= 0 && matrix[i][j-1] > matrix[i][j]) {
            left = 1 + solve(i, j-1, matrix, dp);
        }

        if(j+1 < matrix[i].size() && matrix[i][j+1] > matrix[i][j]) {
            right = 1 + solve(i, j+1, matrix, dp);
        }

        if(i+1 < matrix.size() && matrix[i+1][j] > matrix[i][j]) {
            bottom = 1 + solve(i+1, j, matrix, dp);
        }

        if(i-1 >= 0 && matrix[i-1][j] > matrix[i][j]) {
            top = 1 + solve(i-1, j, matrix, dp);
        }
        return dp[i][j] = max({left, right, top, bottom});
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        int maxi = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int temp = 1 + solve(i, j, matrix, dp);
                maxi = max(maxi, temp);
            }
        }
        return maxi;
    }
};