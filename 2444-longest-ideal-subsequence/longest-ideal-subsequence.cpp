class Solution {
public:
    // int solve(int index, int prev_index, string s, int k,  int n, vector<vector<int>>& dp)
    // {
    //     if(index == n)  return 0;
    //     if(dp[index][prev_index + 1] != -1)
    //         return dp[index][prev_index + 1];

    //     //   not take
    //     int len = 0 + solve(index + 1, prev_index, s, k, n, dp);
    //     if(prev_index == -1 || abs(s[index] - s[prev_index]) <= k)
    //     {
    //         //  take
    //         len = max(len, 1 + solve(index + 1, index, s, k, n, dp));
    //     }
    //     return dp[index][prev_index + 1] = len;
    // }
    int longestIdealString(string s, int k) {

        int n = s.size();
        vector<int> t(26, 0);
        //  t[i] = longest increasing subsequence ending at index i
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            int curr = s[i] - 'a';
            int left = max(0, curr - k);
            int right = min(25, curr + k);

            int longest = 0;
            for(int j = left; j <= right; j++)
            {
                longest = max(t[j], longest);
            }
            t[curr] = max(t[curr], 1 + longest);
            result = max(t[curr], result);
        }
        return result;
    }
};