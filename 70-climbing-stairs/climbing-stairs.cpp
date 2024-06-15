class Solution {

private:

    long long int mod = 1e9 + 7;
    long long countWays(vector<int> &dp, int n) {

        if(n == 0 || n == 1) return 1;
        if(dp[n] != -1) return dp[n];

        return dp[n] = countWays(dp, n-1) + countWays(dp, n - 2);
    }

public:
    int climbStairs(int n) {
        // fibonacci solution
        // vector<int> dp(n + 1, -1);

        // return countWays(dp, n);
        int one_back = 1;
        int two_back = 1;
        for(int i = 2; i <= n; i++) {
            int curr = one_back + two_back;
            two_back = one_back;
            one_back = curr;
        }
        return one_back;
    }
};