class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            int rem = target - nums[i];
            if(mp.find(nums[i]) != mp.end()) {
                return {mp[nums[i]], i};
            }
            mp[rem] = i;
        }
        return {};
    }
};