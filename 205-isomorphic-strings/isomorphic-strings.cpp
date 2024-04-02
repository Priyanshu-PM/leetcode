class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int m = s.size();
        int n = t.size();
        if(s.size() != t.size())  return false;
        unordered_map<char, char> mp;
        set<char> st;

        for(int i = 0; i < m; i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                if(mp[s[i]] != t[i])    return false;
            }
            else 
            {
                if(st.find(t[i]) != st.end())
                {
                    return false;
                }
                mp[s[i]] = t[i];
                st.insert(t[i]);
            }
        }

        return true;
    }
};