class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        
        int maxLen = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 2 == 0 && nums[i] <= threshold) {
                i += 1;
                int f = 1;
                while(i < n) {
                    if((nums[i-1] % 2) == (nums[i] % 2) or nums[i] > threshold)
                        break;
                    f += 1;
                    i += 1;
                }
                i -= 1;
                maxLen = max(maxLen, f);
            }
        }
        return maxLen;
    }
};