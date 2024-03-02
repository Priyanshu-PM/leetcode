class Solution {
private:
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp)
    {
        if(i > j)   return 0;

        if(dp[i][j] != -1)  return dp[i][j];

        int mini = INT_MAX;
        for(int ind = i; ind <= j; ind++)
        {
            int cost = cuts[j+1] - cuts[i-1] + solve(i, ind-1, cuts, dp) + solve(ind+1, j, cuts, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }
public:
    int minCost(int len, vector<int>& cuts) {

        // cuts.insert(cuts.begin(), 0);
        // cuts.push_back(len);
        // sort(cuts.begin(), cuts.end());
        // int c = cuts.size();
        // vector<vector<int>> dp(len, vector<int>(len, -1));
        // return solve(1, c-2, cuts, dp);
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(len);
        int n = cuts.size();
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        
        for(int i = n-2; i >= 1; i--)
        {
            for(int j = i; j <= n-2; j++)
            {
                int mini = INT_MAX;
                for(int k = i; k <= j; k++)
                {
                    mini = min(mini, cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j]);
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][n-2];
    }
};