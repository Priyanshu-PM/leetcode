class Solution {
public:
    string makeGood(string s) {

        stack<char> st;
        map<char, char> mp;
        for(int i = 0; i < 26; i++)
        {
            mp[i + 'a'] = i + 'A';
            mp[i + 'A'] = i + 'a';
        }
        
        for(char c: s)
        {
            if(!st.empty() && mp[st.top()] == c)
            {
                st.pop();
            }
            else    st.push(c);
        }
        string ans = "";
        while(!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};