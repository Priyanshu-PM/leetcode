class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> res;

        for(int i = 0; i < n-2; i++) 
        {
            vector<int> temp;
            for(int j = 0; j < n-2; j++) 
            {
                int v1 = max({grid[i][j], grid[i][j+1], grid[i][j+2]});
                int v2 = max({grid[i+1][j], grid[i+1][j+1], grid[i+1][j+2]});
                int v3 = max({grid[i+2][j], grid[i+2][j+1], grid[i+2][j+2]});

                int val = max({v1, v2, v3});
                temp.push_back(val);
            }
            res.push_back(temp);
        }
        return res;
    }
};