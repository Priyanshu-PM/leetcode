class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        
        int n = nums.size();
        vector<long long> vec(n);
        for(int i = 0; i < n; i++) {
            if(nums[i] % modulo == k)
                vec[i] = 1;
            else
                vec[i] = 0;
        }

        unordered_map<long long, long long> mp;
        mp[0] = 1;

        long long ans = 0, sum = 0;
        for(auto it: vec)
        {
            sum += it;
            long long cmod = ((sum % modulo) + modulo) % modulo;    //  so that modulo does not goes negative
            long long target = (cmod - k + modulo) % modulo;

            if(mp.find(target) != mp.end()) {
                ans += mp[target];
            }
            mp[cmod]++;
        }
        return ans;
    }
};