class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int minLen = INT_MAX;
        for(int i = 0; i < nums.size(); i++)
        {
            int curr = 0;
            for(int j = i; j < nums.size(); j++)
            {
                curr |= nums[j];
                if(curr >= k)
                {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }
        if(minLen == INT_MAX)
            return -1;
        return minLen;
    }
};