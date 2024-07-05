class Solution {
public:
    int beautySum(string s) {
        
        int n = s.size();

        int count = 0;
        for(int i = 0; i < s.size(); i++) {

            unordered_map<int, int> mpp;
            multiset<int> st;
            for(int j = i; j < s.size(); j++)
            {
                if(mpp.find(s[j]) != mpp.end()) {
                    st.erase(st.find(mpp[s[j]]));
                }
                mpp[s[j]]++;
                st.insert(mpp[s[j]]);
                count += (*st.rbegin() - *st.begin());
            }
        }

        return count;
    }
};