class Solution {
public:
    bool isSubstringPresent(string s) {
        
        if(s.size() == 1)   return false;
        if(s.size() == 2 && s[0] == s[1])   return true;
        int n = s.size();
        unordered_map<string, bool> mp;
        for(int i = 0; i < n-1; i++)
        {
            string temp = s.substr(i, 2);
            mp[temp] = true;
        }
        
        for(int i = n-1; i >= 1; i--)
        {
            string temp = "";
            temp += s[i];
            temp += s[i-1];
            if(mp.find(temp) != mp.end())   return true;
        }
        return false;
    }
};