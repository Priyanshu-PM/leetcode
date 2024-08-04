class Solution {
public:
    const int MOD = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<long long> vec;
        for(int i = 0; i < n; i++)
        {
            long long sum = 0;
            for(int j = i; j < n; j++)
            {
                sum += nums[j];
                vec.push_back(sum);
            }
        }
        int l = vec.size();
        sort(vec.begin(), vec.end());
        vector<long long> prefixSum(l+1, 0);
        prefixSum[0] = vec[0];

        for(int i = 1; i < l; i++)  prefixSum[i] = prefixSum[i-1] + vec[i];

        if(left == 1)   return prefixSum[right - 1] % MOD;
        return (prefixSum[right-1] - prefixSum[left-2]) % MOD;
    }
};