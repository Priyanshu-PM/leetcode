class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        // cout << "n is : " << n << endl;
        vector<vector<int>> dp(n + 1, vector<int>(amount+1, 0));

        for(int i = 1; i <= amount; i++) {
            dp[0][i] = 1e8;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                
                if(j < coins[i-1]) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j - coins[i-1]]);
                }
            }
        }   

        cout << endl;
        if(dp[n][amount] != 1e8)
            return dp[n][amount];
            
        return -1;
    }
};