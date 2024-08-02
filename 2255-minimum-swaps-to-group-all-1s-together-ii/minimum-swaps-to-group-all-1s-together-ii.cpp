class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int k = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int cnt = accumulate(nums.begin(), nums.begin() + k, 0);
        int maxi = cnt;

        for(int i = k; i < n+k; i++)
        {
            cnt += nums[i % n] - nums[(i - k + n) % n];
            maxi = max(maxi, cnt);
        }
        return k - maxi;
    }
};