class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        //  dry run on {1, 2, 1, 1, 2}
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans = 0;
        int i = 0, i_prev = 0, j = 0;
        while(j < n)
        {
            mp[nums[j]]++;
            
            while(mp.size() > k)
            {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)    mp.erase(nums[i]);
                i++;
                i_prev = i;
            }

            if(mp.size() == k)
            {
                while(mp[nums[i]] > 1)
                {
                    mp[nums[i]]--;
                    i++;
                }
                ans += (1 + (i - i_prev));
            }
            
            j++;
        }
        // if(mp.size() == k)  ans++;
        return ans;
    }
};