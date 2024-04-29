class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int xorr = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            xorr ^= nums[i];
        }
        
        xorr ^= k;
        
        int cnt = 0;
        while(xorr > 0)
        {
            if(xorr & 1)
                cnt++;
            xorr = xorr >> 1;
        }
        return cnt;
    }
};