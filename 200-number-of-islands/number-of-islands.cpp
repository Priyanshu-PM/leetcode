class Solution {
public:
    void solve(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis)
    {
        vis[row][col] = 1;
        int d[] = {-1, 0, 1, 0, -1};
        for(int k = 0; k < 4; k++)
        {
            int dr = row + d[k];
            int dc = col + d[k+1];

            if(dr >= 0 && dr < grid.size() && dc >= 0 && dc < grid[dr].size() && grid[dr][dc] == '1' && !vis[dr][dc])
            {
                solve(dr, dc, grid, vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int count = 0;
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == '1' && !vis[i][j])
                {
                    count++;
                    solve(i, j, grid, vis);
                }
            }
        }
        return count;
    }
};