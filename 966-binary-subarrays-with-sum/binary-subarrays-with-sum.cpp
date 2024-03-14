class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, count = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            int rem = sum - goal;
            if(mp.find(rem) != mp.end())
            {
                count += mp[rem];
            }
            mp[sum]++;
        }
        return count;
    }
};