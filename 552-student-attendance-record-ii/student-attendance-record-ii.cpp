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

        memset(dp, -1, sizeof(dp));
        int day = n;
        return solve(day, 0, 0);
    }
};