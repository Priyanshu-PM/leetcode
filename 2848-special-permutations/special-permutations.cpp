class Solution {
public:
    const int MOD=1e9+7;
    int solve(int cur,int prev,int mask,vector<int> &nums,vector<vector<int>> &dp){
        if (cur==nums.size())    return 1; // all elements are used, valid permutation
        
        if (dp[prev+1][mask] != -1) {
            return dp[prev+1][mask];
        }

        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if(mask & (1<<i)) continue;
            if(prev==-1 || nums[prev]%nums[i]==0 || nums[i]%nums[prev]==0){
                cnt=(cnt+solve(cur+1,i,mask|(1<<i),nums,dp))%MOD;
            }
        }

        return dp[prev+1][mask] = cnt;
    }

    int specialPerm(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>((1 << n), -1)); 
        return solve(0, -1,0, nums, dp);
    }
};