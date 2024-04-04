class Solution {
public:
    int maxDepth(string s) {
        
        int maxi = 0;
        stack<int> st;
        for(char c: s)
        {
            if(c == '(')
            {
                st.push(c);
                int len = st.size();
                maxi = max(maxi, len);
            }
            if(c == ')')
            {
                st.pop();
            }
        }
        return maxi;
    }
};