class Solution {
private:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    int n, m;
    void solve(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& vis)
    {
        while(!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            vis[r][c] = true;

            for(int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        n = heights.size();
        m = heights[0].size();

        vector<vector<bool>> p(n, vector<bool>(m, false));
        vector<vector<bool>> a(n, vector<bool>(m, false));
        queue<pair<int, int>> q1, q2;

        for(int j = 0; j < m; j++)
        {
            q1.push({0, j});
            p[0][j] = true;
            q2.push({n-1, j});
            a[n-1][j] = true;
        }

        for(int i = 0; i < n; i++)
        {
            q1.push({i, 0});
            p[i][0] = true;
            q2.push({i, m-1});
            a[i][m-1] = true;
        }

        solve(heights, q1, p);
        solve(heights, q2, a);

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(p[i][j] && a[i][j])
                    ans.push_back({i, j});
            }
        }
        
        return ans;
    }
};