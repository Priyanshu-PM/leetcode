class Solution {
private:
    int atMost(vector<int>& nums, int k)
    {
        int n = nums.size();
        int i = 0, res = 0;
        for(int j = 0; j < n; j++) 
        {
            k -= (nums[j] % 2);
            while(k < 0) {
                k += (nums[i] % 2);
                i++;
            }
            res += (j - i + 1);
        }
        return res;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};