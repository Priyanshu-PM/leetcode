class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        int n = points.size();
        sort(points.begin(), points.end());
        int cnt = 1, endPoint = points[0][1];
        // cout << "[ " << points[0][0] << "," << points[0][1] << " ] ";
        for(int i = 1; i < n; i++)
        {
            // cout << "[ " << points[i][0] << "," << points[i][1] << "], ";
            if(points[i][0] <= endPoint)
            {
                endPoint = min(points[i][1], endPoint);
            }
            else
            {
                cnt++;
                endPoint = max(points[i][1], endPoint);
            }
        }

        return cnt;
    }
};