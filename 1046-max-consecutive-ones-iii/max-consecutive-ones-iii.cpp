class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size();
        int maxLength = INT_MIN;
        int i = 0, j = 0, z = 0;
        while(j < n)
        {
            if(nums[j] == 0)
            {
                z++;
            }
            while(z > k)
            {
                if(nums[i] == 0)    z--;
                i++;
            }
            maxLength = max(maxLength, j - i + 1);
            j++;
        }

        return maxLength;
    }
};