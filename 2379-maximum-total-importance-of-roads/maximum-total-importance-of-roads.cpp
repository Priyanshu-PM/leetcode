class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        vector<int> indegree(n, 0);

        //  calculating the frequency of roads for each city
        for(auto it: roads) {
            indegree[it[0]]++;
            indegree[it[1]]++;
        }

        vector<pair<int, int>> vec;
        for(int i = 0; i < n; i++) {
            vec.push_back({indegree[i], i});
        }

        sort(vec.rbegin(), vec.rend());
        map<int, int> mp;
        for(auto it: vec) {
            mp[it.second] = n--;
        }

        long long ans = 0;
        for(auto it: roads) {
            ans += (mp[it[0]] + mp[it[1]]);
        }
        return ans;
    }
};