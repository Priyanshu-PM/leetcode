class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int sum = 0, cnt = 0;
        for(int i = 0; i < n; i++)
        {
            sum = ((sum + nums[i]) % k + k ) % k;
            cnt += mpp[sum];
            mpp[sum]++;
        }
        return cnt;
    }
};