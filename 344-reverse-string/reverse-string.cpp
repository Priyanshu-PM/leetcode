class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int n = s.size();
        for(int i = 0; i < n; i++) {
            
            char temp = s[i];
            s[i] = s[--n];
            s[n] = temp;
            
        }
        
    }
};