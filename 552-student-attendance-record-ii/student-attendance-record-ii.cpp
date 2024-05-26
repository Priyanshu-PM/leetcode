#define ll long long
#define MOD 1000000007

class Solution {
private:
    int dp[100001][2][3];
    int solve(int day, int absent, int conLate) {
        if(absent >= 2 || conLate >= 3)   return 0;
        if(day == 0)    return 1;
        
        //  memoization
        if(dp[day][absent][conLate] != -1)  return dp[day][absent][conLate];

        int pre = solve(day - 1, absent, 0) % MOD;
        int ab = solve(day - 1, absent + 1, 0) % MOD;
        int late = solve(day - 1, absent, conLate + 1) % MOD;

        return dp[day][absent][conLate] = ((pre + ab) % MOD + late) % MOD;
    }
public:
    int checkRecord(int n) {

        memset(dp, 0, sizeof(dp));
        // int day = n;
        // return solve(day, 0, 0);

        for(int i = 0; i <= n; i++) {
            for(int A = 0; A <= 1; A++) {
                for(int L = 0; L <= 2; L++) {

                    if(i == 0) dp[i][A][L] = 1;
                    else {
                        long long ans = 0;
                        ans += dp[i-1][A][0] % MOD;
                        ans += (A == 0) ? dp[i-1][A+1][0] % MOD : 0;
                        ans += (L <= 1) ? dp[i-1][A][L+1] % MOD : 0;

                        dp[i][A][L] = ans % MOD;
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};