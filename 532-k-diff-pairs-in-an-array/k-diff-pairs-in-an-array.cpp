class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(begin(nums), end(nums));
        map<int, int> mp;
        for(int ele: nums)  mp[ele]++;

        int low = 0, high = n-1;
        int ans = 0;
        for(auto it: mp)
        {
            int prev = it.first - k;
            int next = k + it.first;

            if((prev != it.first && mp.find(prev) != mp.end()) || (prev == it.first && it.second > 1)) {
                ans++;
            }
            if(next != it.first && mp.find(next) != mp.end()) {
                ans++;
            }
            mp.erase(it.first);
        }
        return ans;
    }
};