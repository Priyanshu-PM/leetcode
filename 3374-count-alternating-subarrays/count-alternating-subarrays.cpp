class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int left = 0;
        for(int right = 1; right <= n; right++)
        {
            if(right == n || nums[right] == nums[right-1])
            {
                long long len = right - left;
                ans += (len * (len + 1))/2;
                left = right;
            }
        }

        return ans;
    }
};