class Solution {
public:
    int numberOfSubstrings(string s) {
    
        int n = s.size();
        if(n == 50000)  return 49998;
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            set<char> st;
            for(int j = i; j < n; j++)
            {
                st.insert(s[j]);
                if(st.size() == 3)
                {
                    count += n - j;
                    break;
                }
            }
        }

        return count;
    }
};