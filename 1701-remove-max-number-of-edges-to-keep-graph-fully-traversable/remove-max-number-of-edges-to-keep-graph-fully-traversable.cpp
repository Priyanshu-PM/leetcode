class DisjointSet {
public:
    int components;
    vector<int> parent, rank, size;
    DisjointSet(int n)
    {
        components = n;
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node)
    {
        if(node == parent[node])    return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv)    return;

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
        //  decrement the components
        components--;
    }

    bool isSingleComponent() {
        return components == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        DisjointSet alice(n);
        DisjointSet bob(n);

        auto lambda = [](vector<int>& vec1, vector<int>& vec2) {
            return vec1[0] > vec2[0];
        };

        sort(begin(edges), end(edges), lambda);
        
        int edgeCount = 0;

        for(auto it: edges) 
        {
            int type = it[0];
            int u = it[1], v = it[2];

            bool added = false;

            if(type == 3) {
                
                if(alice.findParent(u) != alice.findParent(v)) {
                    alice.unionBySize(u, v);
                    added = true;
                }
                if(bob.findParent(u) != bob.findParent(v)) {
                    bob.unionBySize(u, v);
                    added = true;
                }

                if(added)   edgeCount++;

            }
            else if(type == 2) {
                if(bob.findParent(u) != bob.findParent(v)) {
                    bob.unionBySize(u, v);
                    edgeCount++;
                }

            }
            else if(type == 1) {
                if(alice.findParent(u) != alice.findParent(v)) {
                    alice.unionBySize(u, v);
                    edgeCount++;
                }
            }
        }

        if(alice.isSingleComponent() && bob.isSingleComponent()) {
            return edges.size() - edgeCount;
        }
        return -1;
    }
};