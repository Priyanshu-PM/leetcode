class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        vector<int> degree(n, 0);

        //  calculating the frequency of roads for each city
        for(auto it: roads) {
            degree[it[0]]++;
            degree[it[1]]++;
        }

        sort(degree.begin(), degree.end());
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            ans += (i + 1ll) * degree[i];
        }
        return ans;
    }
};