class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        
        int n = nums.size();
        sort(begin(nums), end(nums));
        int mini = INT_MAX;
        for(int i = 0; i < n-1; i++)
            mini = min(mini, nums[i+1] - nums[i]);
        return mini;
    }
};