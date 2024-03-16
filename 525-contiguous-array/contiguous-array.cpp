class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        int maxLen = 0;
        for(int i = 0; i < nums.size(); i++)
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