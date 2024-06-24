class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int oneCnt = 0, zeroCnt = 0;
        for(char c: s)
        {
            if(c == '0')    zeroCnt++;
            if(c == '1')    oneCnt++;
        }

        string ans = "";
        while(oneCnt > 1)
        {
            ans += '1';
            oneCnt--;
        }
        while(zeroCnt > 0)
        {
            ans += '0';
            zeroCnt--;
        }
        ans += '1';
        return ans;
    }
};