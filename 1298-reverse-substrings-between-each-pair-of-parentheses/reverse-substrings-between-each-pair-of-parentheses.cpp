class Solution {
public:
    string reverseParentheses(string s) {
        
        stack<int> st;
        int n = s.size();
        string result = "";

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(') {
                st.push(result.length());
            }
            else if(s[i] == ')')
            {
                int len = st.top();
                st.pop();
                reverse(result.begin() + len, result.end());
            }
            else {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};