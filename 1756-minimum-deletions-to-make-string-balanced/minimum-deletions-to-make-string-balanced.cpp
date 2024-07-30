class Solution {
public:
    int minimumDeletions(string s) {
        
        //  can be done using prefix sum for left b and right a for index i
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