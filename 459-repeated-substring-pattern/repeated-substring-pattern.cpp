class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int n = s.size();
        for(int i = 1; i < s.size(); i++)
        {
            string sub = s.substr(0, i);
            string temp = "";
            int len = (s.size())/(sub.size());
            for(int t = 0; t < len; t++)
                temp += sub;
            if(temp == s)   return true;
        }
        return false;
    }
};