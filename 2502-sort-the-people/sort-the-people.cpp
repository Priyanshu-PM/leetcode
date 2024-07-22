class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        int n = names.size();
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++)  v.push_back({heights[i], i});
        sort(rbegin(v), rend(v));
        
        vector<string> res;
        for(auto i: v) {
            res.push_back(names[i.second]);
        }
        return res;
    }
};