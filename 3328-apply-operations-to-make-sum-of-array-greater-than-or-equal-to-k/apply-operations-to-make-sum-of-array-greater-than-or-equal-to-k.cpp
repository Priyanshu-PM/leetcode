class Solution {
private:
    int solve(int currNum, int k, int maxElement, vector<vector<int>>& dp)
    {
        if(currNum >= k)    return 0;
        
        if(dp[currNum][maxElement] != -1)   return dp[currNum][maxElement];
        
        int increase = 1 + solve(currNum + 1, k, maxElement + 1, dp);
        
        int add = 1 + solve(currNum + maxElement, k, maxElement, dp);
        return dp[currNum][maxElement] = min(increase, add);
    }
public:
    int minOperations(int k) {
        int n = sqrt(k);
        int res = n + (k-1)/(n) - 1;
        return res;
    }
};