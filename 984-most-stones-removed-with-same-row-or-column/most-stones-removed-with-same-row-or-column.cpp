class DisjointSet {
public:
    vector<int> parent, rank, size;
    DisjointSet(int n)
    {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);

        for(int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1; 
        }
    }

    int findParent(int node)
    {
        if(node == parent[node])
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);


        if(rank[pu] < rank[pv])
        {
            parent[pu] = pv;
            rank[pv]++;
        }
        else if(rank[pv] < rank[pu])
        {
            parent[pv] = pu;
            rank[pu]++;
        }
        else
        {
            parent[pu] = pv;
            rank[pv]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if(size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int n = 0, m = 0;
        int size = stones.size();
        for(auto it: stones)
        {
            n = max(it[0], n);
            m = max(it[1], m);
        }

        unordered_map<long long, int> stoneMap;

        //  columns will be stored after the row
        DisjointSet ds(n + m + 2);
        for(auto it: stones)
        {
            long long row = it[0], col = it[1] + n + 1;
            ds.unionByRank(row, col);

            stoneMap[row] = 1;
            stoneMap[col] = 1;
        }

        int count = 0;
        for(auto it: stoneMap)
        {
            if(ds.findParent(it.first) == it.first) count++;
        }

        return size - count;
    }
};