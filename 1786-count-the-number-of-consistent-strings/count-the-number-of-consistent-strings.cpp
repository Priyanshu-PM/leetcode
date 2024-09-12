class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        unordered_set<char> st;
        for(const auto &c: allowed) st.insert(c);

        int count = 0;
        for(const auto& word: words) {
            bool no = false;
            for(char c: word)   if(st.count(c) == 0) {no = true; break;}
            if(!no) count++;
        }
        return count;
    }
};