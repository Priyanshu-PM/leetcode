class Solution {
public:
    long long countSubstrings(string s, char c) {
        
        long long count = 0;
        for(char ch: s)
        {
            if(ch == c) count++;
        }
        
        long long subStrings = (long long)count*(count + 1)/2;
        return subStrings;
    }
};