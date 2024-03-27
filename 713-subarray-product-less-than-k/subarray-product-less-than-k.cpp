class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k <= 1)  return 0;
        int n = nums.size();
        int i = 0, j = 0, count = 0;
        long long pro = 1;
        while(j < n)
        {
            pro = pro * nums[j];
            while(pro >= k) pro = pro / nums[i++];
            count += (j - i + 1);
            j++;
        }
        return count;
    }
};