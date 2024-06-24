class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {

        int n = nums.size();
        int ans = 0, flips = 0;
        
        for(int i = 0; i < n; i++)
        {
            if((nums[i] + flips) % 2 == 0) {
                if(i > n - k) {
                    return -1;
                }
                else {
                    ans++;
                    flips++;
                    nums[i] = -1;
                }
            }
            if(i+1 >= k) {
                flips -= (nums[i - k + 1] < 0);
            }
        }
        return ans;
    }
};