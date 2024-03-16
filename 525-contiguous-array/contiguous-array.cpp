class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        int maxLen = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 1)    sum++;
            else    sum--;
            if(mp.find(sum) != mp.end())
            {
                maxLen = max(maxLen, i - mp[sum]);
            }
            else
                mp[sum] = i;
        }
        return maxLen;
    }
};