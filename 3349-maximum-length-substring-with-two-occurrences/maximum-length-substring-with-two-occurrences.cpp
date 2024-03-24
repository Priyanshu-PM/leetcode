class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        int maxLen = 0;
        for(int i = 0; i < s.size(); i++)
        {
            unordered_map<char, int> mp;
            int maxFreq = 0;
            for(int j = i; j < s.size(); j++)
            {
                mp[s[j]]++;
                maxFreq = max(maxFreq, mp[s[j]]);
                if(mp[s[j]] <= 2 && maxFreq <= 2)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};