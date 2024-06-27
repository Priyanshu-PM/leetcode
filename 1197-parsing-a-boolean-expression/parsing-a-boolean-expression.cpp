class Solution {
private:
    bool solve(stack<char>& st)
    {
        bool hasFalse = false;
        bool hasTrue = false;
        while(!st.empty())
        {
            if(st.top() != '&' && st.top() != '|' && st.top() != '!') {
                if(st.top() == 't') hasTrue = true;
                else    hasFalse = true;
                st.pop();
            }
            else if(st.top() == '&') {
                st.pop();
                if(hasFalse == true)    return false;
                return true;
            }
            else if(st.top() == '|') {
                st.pop();
                if(hasTrue == true) return true;
                return false;
            }
            else if(st.top() == '!') {
                st.pop();
                if(hasTrue) return false;
                return true;
            }
        }
        return false;
    }

public:
    bool parseBoolExpr(string exp) {
        
        int n = exp.size();
        stack<char> st;
        
        for(int i = 0; i < n; i++)
        {
            if(exp[i] != '(' && exp[i] != ')' && exp[i] != ',')
            {
                st.push(exp[i]);
            }
            else if(exp[i] == ')') {

                char ans = solve(st) ? 't' : 'f';
                st.push(ans);
            }
        }

        if(st.top() == 't') return true;
        return false;
    }
};