#include <cmath>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int n = strs.size();
        sort(strs.begin(), strs.end());
        string first = strs[0], last = strs[n-1];
        for(int i = 0; i < min(first.length(), last.length()); i++)
        {
            if(first[i] != last[i])
            {
                return prefix;
            }
            prefix += first[i];
        }
        return prefix;
    }
};