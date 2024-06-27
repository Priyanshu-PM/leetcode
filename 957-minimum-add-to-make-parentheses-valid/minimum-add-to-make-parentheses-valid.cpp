class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int open = 0, ans = 0;
        for(char c: s)
        {
            if(c == ')') {
                if(open > 0)  open--;
                else {
                    ans++;
                }
            }
            else if(c == '(')   open++;
        }
        return ans + open;
    }
};