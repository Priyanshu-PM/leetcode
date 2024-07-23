class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int a = INT_MAX, b = 0, c = INT_MAX, d = 0;
        for(auto x: prices)
        {
            a = min(a, x);
            b = max(b, x-a);
            c = min(c, x-b);
            d = max(d, x-c);
        }
        return d;
    }
};