class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int n = intervals.size();
        int new_start = newInterval[0];
        int new_end = newInterval[1];

        vector<vector<int>> ans;
        int i = 0;
        while(i < n && intervals[i][1] < new_start)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        
        while(i < n && intervals[i][0] <= new_end)
        {
            new_start = min(new_start, intervals[i][0]);
            new_end = max(new_end, intervals[i][1]);
            i++;
        }

        ans.push_back({new_start, new_end});

        while(i < n)
        { 
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};