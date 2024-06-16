class Solution {
private:
    void solve(int num, int n, int k, vector<vector<int>>& ans, vector<int> output)
    {
        if(output.size() == k) {
            ans.push_back(output);
            return;
        }

        for(int i = num; i <= n; i++) {
            output.push_back(i);
            solve(i+1, n, k, ans, output);
            output.pop_back();
        }

    }
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ans;
        vector<int> output;
        solve(1, n, k, ans, output);
        return ans;
    }
};