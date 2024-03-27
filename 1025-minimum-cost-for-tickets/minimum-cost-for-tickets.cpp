class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<int> span = {1, 7, 30};
        int n = days.size();
        vector<int> dp(n+1, 0);
        for(int i = n-1; i >= 0; i--)
        {
            dp[i] = 1e8;
            for(int j = 0; j < 3; j++)
            {
                int m = i;
                while(m < n && days[m] < days[i] + span[j])
                {
                    m++;
                }
                dp[i] = min(dp[i], costs[j] + dp[m]);
            }
        }
        return dp[0];
    }
};