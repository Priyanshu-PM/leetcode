class Solution {
private:
    void dfs(int node, int dest, vector<int> path, vector<vector<int>>& res, vector<vector<int>>& graph)
    {
        if(node == dest) {
            path.push_back(node);
            res.push_back(path);
            return;
        }

        path.push_back(node);
        for(auto it: graph[node]) {
            dfs(it, dest, path, res, graph);
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();

        vector<vector<int>> res;
        vector<int> path;
        dfs(0, n-1, path, res, graph);
        return res;
    }
};