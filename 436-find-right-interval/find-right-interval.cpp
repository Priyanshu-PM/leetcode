class Solution {
public:
    int solve(vector<vector<int>>& vec, int target)
    {
        int low = 0, high = vec.size()-1;
        int ans = -1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(vec[mid][0] >= target) {
                ans = vec[mid][2];
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        vector<vector<int>> vec;
        for(int i = 0; i < n; i++) {
            vec.push_back({intervals[i][0], intervals[i][1], i});
        }
        sort(begin(vec), end(vec));

        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++)
        {
            ans[i] = solve(vec, intervals[i][1]);
        }

        return ans;
    }
};