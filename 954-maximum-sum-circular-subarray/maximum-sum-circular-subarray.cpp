class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n = nums.size();
        int totalSum = nums[0], ans = nums[0];

        //  normal KADANE's algorithm
        int sum = nums[0];

        for(int i = 1; i < n; i++) {
            sum += nums[i];
            totalSum = max(totalSum + nums[i], nums[i]);
            ans = max(ans, totalSum);
        }

        cout << "ans - " << ans << endl;

        totalSum = nums[0];
        int mini = nums[0];

        //  KADANE's minimum algorithm
        for(int i = 1; i < n; i++)
        {
            totalSum = min(totalSum + nums[i], nums[i]);
            mini = min(mini, totalSum);
        }

        if(ans > 0)
            return max(ans, sum - mini);
        return ans;
    }
};