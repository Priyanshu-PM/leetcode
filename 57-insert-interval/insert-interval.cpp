class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int n = intervals.size();
        if(n == 0)  return {newInterval};   //  base case

        bool inserted = false;

        for(int i = 0; i < n; i++)
        {
            if(!inserted && intervals[i][0] > newInterval[0])
            {
                intervals.insert(intervals.begin() + i, newInterval);
                inserted = true;
                break;
            }
        }

        if(!inserted)    intervals.push_back(newInterval);

        n = intervals.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) 
        {
            if (ans.empty() || intervals[i][0] > ans.back()[1]) 
            {
                ans.push_back(intervals[i]);
            }
            // if the current interval
            // lies in the last interval:
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};