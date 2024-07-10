class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        if(n == 1)  return 1;
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                int dy = (points[i][1] - points[j][1]);
                int dx = (points[i][0] - points[j][0]);

                int count = 2;
                for(int k = j+1; k < n; k++)
                {
                    int dy_ = (points[k][1] - points[i][1]);
                    int dx_ = (points[k][0] - points[i][0]);

                    if(dx * dy_ == dx_ * dy)
                        count++;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};