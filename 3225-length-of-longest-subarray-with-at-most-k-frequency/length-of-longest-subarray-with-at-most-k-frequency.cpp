class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        int n = nums.size();
        int i = 0, j = 0;
        int maxLen = 0;
        while(j < n)
        {
            mp[nums[j]]++;
            if(mp[nums[j]] <= k)
                maxLen = max(maxLen, j - i + 1);
            else
            {
                while(mp[nums[j]] > k)
                {
                    mp[nums[i]]--;
                    i++;
                }
            }
            j++;
        }
        return maxLen;
    }
};