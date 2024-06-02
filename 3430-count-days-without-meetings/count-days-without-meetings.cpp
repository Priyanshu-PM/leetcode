class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        sort(meetings.begin(), meetings.end());

        //  merging the intervals
        vector<vector<int>> ans;

        for(int i = 0; i < meetings.size(); i++) {

            if(ans.empty() || meetings[i][0] > ans.back()[1]) {
                ans.push_back(meetings[i]);
            }
            else {
                ans.back()[1] = max(ans.back()[1], meetings[i][1]);
            }
        }

        
        int free = 0, prevEnd = ans[0][1];
        free += ans[0][0] - 1;
        for(int i = 1; i < ans.size(); i++) 
        {
            // cout << "{" << ans[i][0] << ", " << ans[i][1] << "} ";
            free += (ans[i][0] - prevEnd - 1);
            prevEnd = ans[i][1];
        }

        free += (days - ans[ans.size()-1][1]);
        return free;
    }
};