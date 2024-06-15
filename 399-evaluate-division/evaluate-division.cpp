class Solution {
private:
    void solve(string src, string dest, map<string, vector<pair<string, double>>>& mp, unordered_set<string>& vis, double product, double &ans)
    {
        if(vis.find(src) != vis.end())  return;

        vis.insert(src);
        
        if(src == dest) {
            ans = product;
            return;
        }

        for(auto it: mp[src]) {
            solve(it.first, dest, mp, vis, product* it.second, ans);
        }
        return;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        map<string, vector<pair<string, double>>> mp;
        int n = equations.size();
        for(int i = 0; i < n; i++)
        {
            string u = equations[i][0], v = equations[i][1];
            mp[u].push_back({v, values[i]});
            mp[v].push_back({u, 1/values[i]});
        }

        vector<double> result;
        for(int i = 0; i < queries.size(); i++)
        {
            string u = queries[i][0], v = queries[i][1];
            double ans = -1.0;
            double product = 1.0;
            if(mp.find(u) != mp.end()) 
            {
                unordered_set<string> vis;
                double product = 1.0;
                solve(u, v, mp, vis, product, ans);
            }
            result.push_back(ans);
        }

        return result;
    }
};