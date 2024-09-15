class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> mp(32, -2);
        mp[0] = -1;

        int maxLen = 0, mask = 0;

        for(int i = 0; i < s.size(); i++)
        {
            char c = s[i];

            switch(c) {
                case 'a':
                    mask ^= 1;
                    break;
                case 'e':
                    mask ^= 2;
                    break;
                case 'i':
                    mask ^= 4;
                    break;
                case 'o':
                    mask ^= 8;
                    break;
                case 'u':
                    mask ^= 16;
                    break;
            }

            int prev = mp[mask];
            if(prev == -2) {
                mp[mask] = i;
            }
            else {
                maxLen = max(maxLen, i - prev);
            }

        }

        return maxLen;
    }
};