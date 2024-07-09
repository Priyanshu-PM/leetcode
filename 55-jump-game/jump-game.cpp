class Solution {

private:
    bool solve(int index, vector<int>& nums, vector<int>& dp, int n) {

        if(index >= n) {
            return dp[index] =  1;
        }
        if(index == n-1) {
            return dp[index] = 1;
        }   

        if(dp[index] != -1) return dp[index];

        for(int i = 1; i <= nums[index]; i++) {

            if(index + i < n) 
            {
                if(solve(index+i, nums, dp, n) == 1) {
                    return dp[index] = 1;
                }
            }
        }
        return dp[index] = 0;
    }

public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n, -1);

        if(solve(0, nums, dp, n) == 1)
            return true;

        return false;
    }
};