class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(sum > nums[i])   return false;
            nums[i] -= sum;
            sum += nums[i];
            if(i >= k-1) {
                sum -= nums[i - k + 1];
            }
        }
        return sum == 0;
    }
};