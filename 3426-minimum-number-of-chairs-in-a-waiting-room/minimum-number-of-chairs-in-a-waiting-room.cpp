class Solution {
public:
    int minimumChairs(string s) {
        int maxcnt = 0, cnt = 0;
        for(char c: s) {
            if(c == 'E') {
                cnt++;
                maxcnt = max(maxcnt, cnt);
            }
            else {
                cnt--;
            }
        }
        return maxcnt;
    }
};