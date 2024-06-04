class Solution {

public:
    int longestPalindrome(string s) {
        int oddCount = 0;
        int hashMap[256] = {0};
        for(char c: s) {
            hashMap[c]++;
            if(hashMap[c] % 2 == 1) {
                oddCount++;
            }
            else {
                oddCount--;
            }
        }

        if(oddCount > 1)
            return s.length() - oddCount + 1;

        return s.length();

    }
};