class Solution {
private:
    int solve(int index, vector<int>& nums, int &target, vector<int>& dp) {
        int n = nums.size();
        if(index == 0)  return 0;
        if(dp[index] != -1) return dp[index];

        int jumps = 0;
        for(int i = index-1; i >= 0; i--) {
            if(abs(nums[index] - nums[i]) <= target) {
                int temp = solve(i, nums, target, dp);
                if(temp != -1)  jumps = max(jumps, temp + 1);
            }
        }
        
        dp[index] = jumps != 0 ? jumps: -1;
        return dp[index];
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        // return solve(n-1, nums, target, dp);
        for(int index = 1; index < n; index++)
        {
            int jumps = 0;
            for(int i = index-1; i >= 0; i--) {
                
                if(abs(nums[index] - nums[i]) <= target) {
                    int njumps = dp[i];
                    if(njumps != -1)  jumps = max(jumps, njumps + 1);
                }
            }
            dp[index] = jumps != 0 ? jumps : -1;
        }
        return dp[n-1];
    }
};