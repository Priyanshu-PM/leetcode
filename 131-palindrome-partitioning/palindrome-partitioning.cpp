class Solution {

private:

    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    void solve(vector<vector<string>>& ans, vector<string> ds, int index, string s, int n) {

        if(index == n) {
            ans.push_back(ds);
            return;
        } 
        for(int i = index; i < n; i++) {
            if(isPalindrome(s, index, i)) {
                ds.push_back(s.substr(index, i - index + 1));
                solve(ans, ds, i+1, s, n);
                ds.pop_back();
            }
        }
        
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        int n = s.size();
        solve(ans, ds, 0, s, n);
        return ans;
    }
};