class Solution {

private:
    int f(vector<int> &arr, int ind, int k, int n, vector<int> &dp) {

        if(ind == n) return 0;
        if(dp[ind] != -1) return dp[ind];
        int maxi = 0, maxAns = 0, len = 0;
        for(int j = ind; j < min(ind+k, n); j++) {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len * maxi + f(arr, j+1, k, n, dp);
            maxAns = max(maxAns, sum);
        }

        return dp[ind] = maxAns;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(arr, 0, k, n, dp);
    }
};