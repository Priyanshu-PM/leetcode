class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // return solve(0, -1, nums, dp, n);

        //  Space optimised approach

        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        vector<int> next(n+1, 0), curr(n+1, 0);

        for(int index = n-1; index >= 0; index--)
        {
            for(int prev_index = index - 1; prev_index >= -1; prev_index--)
            {
                int len = 0 + next[prev_index + 1];

                if(prev_index == -1 || nums[prev_index] < nums[index])
                {
                    len = max(len, 1 + next[index + 1]);
                }

                curr[prev_index + 1] = len;
            }
            next = curr;
        }
        return next[0];
    }
};