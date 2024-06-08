class Solution {
public:
    int solve(int ind, int tk, int k, vector<int>& nums, int prevIndex, vector<vector<vector<int>>>& dp) {
        if (ind == nums.size()) {
            return 0;
        }
        
        if (dp[ind][tk][prevIndex + 1] != -1) {
            return dp[ind][tk][prevIndex + 1];
        }
        
        // Not pick the current element
        int notPick = solve(ind + 1, tk, k, nums, prevIndex, dp);
        
        // Pick the current element
        int pick = 0;
        if (tk + (prevIndex != -1 && nums[ind] != nums[prevIndex] ? 1 : 0) <= k) {
            pick = 1 + solve(ind + 1, tk + (prevIndex != -1 && nums[ind] != nums[prevIndex] ? 1 : 0), k, nums, ind, dp);
        }
        
        return dp[ind][tk][prevIndex + 1] = max(pick, notPick);
    }
    
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(n + 1, -1)));
        return solve(0, 0, k, nums, -1, dp);
    }
};
