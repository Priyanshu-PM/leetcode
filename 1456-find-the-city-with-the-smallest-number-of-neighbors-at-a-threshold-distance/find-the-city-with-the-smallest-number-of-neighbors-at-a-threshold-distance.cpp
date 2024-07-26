class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> graph(n, vector<int>(n, 1e9));

        //  creating the graph of cities
        for(auto it: edges)
        {
            int u = it[0], v = it[1];

            graph[u][v] = it[2];
            graph[v][u] = it[2];
        }

        for(int i = 0; i < n; i++)  graph[i][i] = 0;

        for(int via = 0; via < n; via++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    graph[i][j] = min(graph[i][j], graph[i][via] + graph[via][j]);
                }
            }
        }

        int mini = INT_MAX;
        int city = -1;
        for(int i = 0; i < n; i++)
        {
            int currCount = 0;
            for(int j = 0; j < n; j++)
            {
                if(graph[i][j] <= distanceThreshold)    currCount++;
            }
            if(mini >= currCount)
            {
                city = i;
                mini = currCount;
            }
        }
        return city;
    }
};