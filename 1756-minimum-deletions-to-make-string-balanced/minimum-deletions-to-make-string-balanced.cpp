class Solution {
public:
    int minimumDeletions(string s) {
        
        stack<char> st;
        int cnt = 0;
        for(char c: s) {
            if(!st.empty() && st.top() == 'b' && c == 'a') {
                st.pop();
                cnt++;
            }
            else {
                st.push(c);
            }
        }

        return cnt;
    }
};