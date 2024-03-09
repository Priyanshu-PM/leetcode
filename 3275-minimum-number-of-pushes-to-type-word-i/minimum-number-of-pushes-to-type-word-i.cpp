class Solution {
public:
    int minimumPushes(string word) {
        
        vector<int> freq(26);
        for(char c: word)   freq[c - 'a']++;
        
        sort(freq.rbegin(), freq.rend());
        
        int ans = 0;
        int curr = 1, used = 0;
        for(auto x: freq)
        {
            ans += curr*x;
            ++used;
            if(used == 8)
            {
                ++curr;
                used = 0;
            }
        }
        
        return ans;
    }
};