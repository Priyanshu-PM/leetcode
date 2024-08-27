class Solution {
private:
    using v = pair<int, double>;
    void createAdjacencyList(vector<vector<int>>& edges, vector<double>& succProb, vector<v> adjList[])
    {
        int len = edges.size();
        for(int i = 0; i < len; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adjList[u].push_back({v, succProb[i]});
            adjList[v].push_back({u, succProb[i]});
        }
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        vector<v> adjList[n];
        createAdjacencyList(edges, succProb, adjList);

        vector<double> dist(n, 0);

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        dist[start_node] = 1.0;


        while(!pq.empty())
        {
            auto [dis, node] = pq.top();
            pq.pop();
            
            if(node == end_node)    return dis;

            for(auto [neigh, path]: adjList[node])
            {
                double new_prob = dis * path;

                if(new_prob > dist[neigh]) {
                    dist[neigh] = dist[node] * path;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        return 0.0;
    }
};