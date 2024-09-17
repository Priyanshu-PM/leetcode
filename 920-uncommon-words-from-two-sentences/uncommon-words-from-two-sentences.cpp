class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        string s = s1 + " " + s2;
        
        unordered_map<string, int> mp;
        string tmp = "";
        for(auto &val: s) {
            if(val == ' ') {
                mp[tmp]++;
                tmp = "";
            }
            else {
                tmp += val;
            }
        }

        if(tmp != "") {
            mp[tmp]++;
            tmp = "";
        }

        vector<string> ans;
        for(auto &val: mp) {
            if(val.second == 1) {
                ans.push_back(val.first);
            }
        }
        return ans;
    }
};