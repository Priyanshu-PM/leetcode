class Solution {

private:
    int findMinPath(vector<vector<int>>& triangle, int i, int j, int m, vector<vector<int>>& dp) {

        // memoization method

        // base case
        if(i == m-1) {
            int mini = INT_MAX;
            for(int k = j; k < min(i+1, j+2); k++) {
                if(triangle[i][k] < mini) {
                    mini = triangle[i][k];
                }
            }
            return mini;
        }
        
        // checking for overlapping subproblems
        if(dp[i][j] != -1)  return dp[i][j];
        int mini = INT_MAX;

        // recursive call for i and i + 1
        for(int k = j; k < min(i+1, j+2); k++) {
            int ans = triangle[i][k] + findMinPath(triangle, i+1, k, m, dp);

            mini = min(ans, mini);
        }

        return dp[i][j] = mini;

    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m = triangle.size();
        int n = triangle[m-1].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return findMinPath(triangle, 0, 0, m, dp);
    }
};