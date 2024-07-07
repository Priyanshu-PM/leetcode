class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int ans = numBottles;
        while(numBottles >= numExchange)
        {
            int rem = numBottles % numExchange;
            int extra = numBottles / numExchange;

            numBottles = rem + extra;
            ans += extra;
        }
        return ans;
    }
};