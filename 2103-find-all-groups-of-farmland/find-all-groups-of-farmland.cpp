class Solution {
public:
    void solve(int row, int col, vector<int>& temp, vector<vector<int>>& land, vector<vector<int>>& vis, int n, int m)
    {
        vis[row][col] = 1;
        if(row <= temp[0] && col <= temp[1])
        {
            temp[0] = row;
            temp[1] = col;
        }

        if(row >= temp[2] && col >= temp[3])
        {
            temp[2] = row;
            temp[3] = col;
        }

        int d[] = {-1, 0, 1, 0, -1};
        for(int i = 0; i < 4; i++)
        {
            int dr = row + d[i];
            int dc = col + d[i + 1];

            if(dr >= 0 && dr < n && dc >= 0 && dc < m && land[dr][dc] == 1 && !vis[dr][dc])
                solve(dr, dc, temp, land, vis, n, m);
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        int n = land.size();
        int m = land[0].size();

        vector<vector<int>> ans;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(land[i][j] == 1 && !vis[i][j])
                {
                    vector<int> temp = {INT_MAX, INT_MAX, INT_MIN, INT_MIN};
                    solve(i, j, temp, land, vis, n, m);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};