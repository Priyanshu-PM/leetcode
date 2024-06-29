class Solution {
private:
    void dfs(vector<int> adjList[], int parent, int node, vector<vector<int>>& res, vector<bool>& visit)
    {
        visit[node] = true;
        for(int neigh: adjList[node]) {
            if(!visit[neigh]) {
                res[neigh].push_back(parent);
                dfs(adjList, parent, neigh, res, visit);
            }
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> res(n);
        vector<int> adjList[n];

        //  adjacency list creation
        for(auto it: edges) {
            int u = it[0], v = it[1];
            adjList[u].push_back(v);
        }

        for(int i = 0; i < n; i++)
        {
            vector<bool> visit(n, false);
            dfs(adjList, i, i, res, visit);
        }

        for(int i = 0; i < n; i++) {
            sort(res[i].begin(), res[i].end());
        }

        return res;
    }
};