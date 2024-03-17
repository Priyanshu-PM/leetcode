class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int n = intervals.size();
        if(n == 0)  return {newInterval};

        bool inserted = false;
        // if(newInterval[1] < intervals[0][0])
        // {
        //     intervals.insert(intervals.begin(), newInterval);
        //     inserted = true;
        // }

        for(int i = 0; i < n; i++)
        {
            if(!inserted && intervals[i][0] > newInterval[0])
            {
                intervals.insert(intervals.begin() + i, newInterval);
                inserted = true;
            }
        }

        if(!inserted)
        {
            intervals.push_back(newInterval);
        }

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
    
        // vector<vector<int>> merged;
        // int i = 0;

        // while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
        //     merged.push_back(intervals[i]);
        //     i++;
        // }

        // while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
        //     newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
        //     i++;
        // }
        // merged.push_back(newInterval);

        // while (i < intervals.size()) {
        //     merged.push_back(intervals[i]);
        //     i++;
        // }

        // return merged;
    }
};