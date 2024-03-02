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
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>>dp(m+2, vector<int>(m+2, 0));
        for(int i = m; i >= 1; i--){
            for(int j = 1; j <= m; j++){
                if(i > j){continue;}
                int mini = INT_MAX;
                for(int k = i; k <= j; k++)
                {
                    int ans = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    mini = min(mini, ans);
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][m];
    }
};