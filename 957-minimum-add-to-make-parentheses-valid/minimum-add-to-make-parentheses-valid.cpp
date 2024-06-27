class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char> st;
        int ans = 0;
        for(char c: s)
        {
            if(c == ')') {
                if(!st.empty() && st.top() == '(')  st.pop();
                else    ans++;
            }
            else if(c == '(')   st.push(c);
        }
        return ans + st.size();
    }
};