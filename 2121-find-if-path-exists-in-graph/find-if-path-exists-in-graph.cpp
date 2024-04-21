class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        if(source == destination)   return true;
        vector<int> adjList[n];
        for(auto it : edges)
        {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n, false);
        queue<int> q;
        q.push(source);
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            if(vis[node])   continue;
            vis[node] = true;

            for(auto v: adjList[node])
            {
                if(v == destination)
                    return true;
                else if(!vis[v])
                    q.push(v);
            }
        }
        return false;
    }
};