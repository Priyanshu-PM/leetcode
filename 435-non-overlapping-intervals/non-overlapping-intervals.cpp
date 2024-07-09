class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int cnt = 0;
        vector<int> prev = {intervals[0][0], intervals[0][1]};

        for(int i = 1; i < n; i++)
        {
            if(intervals[i][0] < prev[1])
            {
                cnt++;
                if(prev[1] >= intervals[i][1])
                {
                    prev[0] = intervals[i][0];
                    prev[1] = intervals[i][1];
                }
            }
            else
            {
                prev[0] = intervals[i][0];
                prev[1] = intervals[i][1];
            }
        }

        return cnt;
    }
};