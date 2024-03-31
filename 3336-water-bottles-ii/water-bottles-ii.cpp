class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int count = 0;
        int ans = numBottles;
        while(numBottles >= numExchange)
        {
            count++;
            numBottles -= numExchange;
            numBottles++;
            numExchange++;
        }
        return ans + count;
    }
};