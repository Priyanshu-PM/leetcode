class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        
        int n = nums.size();
        vector<long long> ans(n, 0);
        unordered_map<long long, long long> mp;
        multiset<long long> mst;
        for(int i = 0; i < nums.size(); i++)
        {
            int curr = mp[nums[i]];
            if(mp.find(nums[i]) == mp.end())   mp[nums[i]] = freq[i];
            else    mp[nums[i]] += freq[i];

            if(mst.find(curr) != mst.end()) mst.erase(mst.find(curr));
            mst.insert(mp[nums[i]]);
            long long maxi = *mst.rbegin();
            ans[i] = maxi;
        }
        
        return ans;
    }
};