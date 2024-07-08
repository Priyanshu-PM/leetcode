class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char, int> alphabets;
        int ans = 0;
        int left = 0;
        int right = 0;
        int maxFreq = 0;

        for(right = 0; right < s.size(); right++)
        {
            alphabets[s[right]] = 1 + alphabets[s[right]];
            maxFreq = max(maxFreq, alphabets[s[right]]);

            if((right - left + 1) - maxFreq > k)
            {
                alphabets[s[left]] -= 1;
                left++;
            }
            else
            {
                ans = max(ans, (right - left + 1));
            }
        }

        return ans;
    }
};