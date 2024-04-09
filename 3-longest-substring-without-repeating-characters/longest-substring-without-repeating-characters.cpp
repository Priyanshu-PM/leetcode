class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int n = s.length();
        unordered_set<char> elements;
        int left = 0;
        for(int right = 0; right < n; right++) {
            if(elements.count(s[right]) == 0) {
                elements.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
            }
            else {
                while(elements.count(s[right]) != 0) {
                    elements.erase(s[left]);
                    left++;
                }
                elements.insert(s[right]);
            }
        }
        

        return maxLength;
    }
};