class Solution {
public:
    string reverseWords(string s) {

        //  solved it on my own
        stack<char> st;
        int n = s.size();
        int i = 0;
        string ans = "";
        while(i < n) {
            while(s[i] == ' ') i++;
            while(((int)s[i] >= 65 && (int)s[i] <= 90) || ((int)s[i] >= 48 && (int)s[i] <= 57) || ((int)s[i] >= 97 && (int)s[i] <= 126) ) {
                st.push(s[i]);
                i++;
            }
            while(!st.empty()) {
                ans = st.top() + ans;
                st.pop();
            }
            ans = " " + ans;
            while(s[i] == ' ') i++;
        }  

        return ans.substr(1, ans.size());
    }
};