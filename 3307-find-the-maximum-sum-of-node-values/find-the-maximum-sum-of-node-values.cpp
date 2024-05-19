class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> lis(n);
        
        for (int i = 0; i < n; i++) {
            lis[i] = vector<int>();
        }
        
        for (int i = 0; i < n - 1; i++) {
            lis[edges[i][0]].push_back(edges[i][1]);
            lis[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> inc;
        
        for (int i = 0; i < n; i++) {
            long val = static_cast<long>(nums[i]) ^ k;
            if (val > nums[i]) {
                inc.push_back(i);
            }
        }
        
        int sz = inc.size();
        long ans = 0;
        
        for (int num : nums) {
            ans += num;
        }
        
        if (sz % 2 == 0) {
            for (int i : inc) {
                ans -= nums[i];
                long add = static_cast<long>(nums[i]) ^ k;
                ans += add;
            }
        } else {
            long hue = ans;
            for (int i : inc) {
                ans -= nums[i];
                long add = static_cast<long>(nums[i]) ^ k;
                ans += add;
            }
            for (int i = 0; i < sz; i++) {
                long add = static_cast<long>(nums[inc[i]]) ^ k;
                long curr_ans = ans - add + nums[inc[i]];
                hue = max(hue, curr_ans);
            }
            vector<int> vis(n, 0);
            for (int i = 0; i < sz; i++) {
                vis[inc[i]] = 1;
            }
            for (int i = 0; i < n; i++) {
                if (vis[i] == 0) {
                    long add = static_cast<long>(nums[i]) ^ k;
                    long curr_ans = ans - nums[i] + add;
                    hue = max(hue, curr_ans);
                }
            }
            ans = hue;
        }
        
        return ans;
    }
};