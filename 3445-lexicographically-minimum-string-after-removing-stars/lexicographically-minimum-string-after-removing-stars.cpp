class Solution {
public:
    string clearStars(string s) {
        
        set<pair<int, int>> st;
        set<int> del;
        int stars = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '*') {
                auto it = *st.begin();
                st.erase(st.begin());
                del.insert(-it.second);
                del.insert(i);
            }
            else {
                st.insert({s[i] - 'a', -i});
            }
        }
        string ans = "";
        for(int i = 0; i < s.size(); i++) {
            if(!del.count(i))
                ans += s[i];
        }
        return ans;
    }
};