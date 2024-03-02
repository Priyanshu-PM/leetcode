class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n, 1), hash(n, 1);
        int maxi = 1;
        for(int i = 0; i < n; i++) {
            for(int prev = 0; prev < i; prev++) {

                if(nums[i] > nums[prev] && dp[i] < 1 + dp[prev]) 
                {
                    hash[i] = hash[prev];
                    dp[i] = 1 + dp[prev];
                }
                else if(nums[i] > nums[prev] && dp[i] == 1 + dp[prev])
                {
                    hash[i] += hash[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            cout << dp[i] << " ";
            if(dp[i] == maxi)   ans += hash[i];   
        }

        return ans;
    }
};