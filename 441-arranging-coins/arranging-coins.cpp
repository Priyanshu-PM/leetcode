class Solution {
public:
    int arrangeCoins(int n) {
        
        int ans = -1;
        for(int i = 0; i <= n; i++) {

            long long temp = (long long)i*(i+1)/2;
            if(temp > n)    break;
            ans = i;
        }
        return ans;
    }
};