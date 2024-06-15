class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        //  kahn's algorithm

        //  T.C = O(V + E) for directed graph
        //  S.C = O(2N) for indegree array and queue
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto edge: prerequisites)
        {
            adjList[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        int cnt = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;

            for(auto it: adjList[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        if(cnt == numCourses)
            return 1;

        return 0;
    }
};