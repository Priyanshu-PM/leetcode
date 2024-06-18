class Solution {
private:
    int func(int index, int buy, int rem, vector<int> &values, int n, vector<vector<vector<int>>> &dp) {
        
        if(n == index)    return 0;
        if(dp[index][buy][rem] != -1) return dp[index][buy][rem];

        int profit = 0;
        if(buy) {
            if(rem > 0)
                profit = max(-values[index] + func(index+1, 0, rem, values, n, dp),
            0 + func(index+1, 1, rem, values, n, dp));
        }
        else {
            profit = max(values[index] + func(index+1, 1, rem-1, values, n, dp),
            0 + func(index+1, 0, rem, values, n, dp));
        }
 
        return dp[index][buy][rem] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2+1, vector<int>(k+1, -1)));
        // return func(0, 1, k, prices, n, dp);
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2+1, vector<int>(k+1, 0)));
        vector<vector<int>> next(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0)); 

        for(int index = n-1; index >= 0; index--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                for(int rem = 1; rem <= k; rem++)
                {
                    int profit = 0;
                    if(buy) {
                        profit = max(-prices[index] + next[0][rem],
                        0 + next[1][rem]);
                    }
                    else {
                        profit = max(prices[index] + next[1][rem-1],
                        0 + next[0][rem]);
                    }
            
                    curr[buy][rem] = profit;
                }
            }
            next = curr;
        }
        return next[1][k];
    }
};