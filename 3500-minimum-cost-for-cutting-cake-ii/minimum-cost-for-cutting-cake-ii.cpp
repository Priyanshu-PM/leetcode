class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        
        sort(begin(h), end(h));
        sort(begin(v), end(v));

        long long ans = 0;
        long long sumh = 0, sumv = 0;
        for(int e: h)   sumh += e;
        for(int e: v)   sumv += e;

        int i = h.size()-1, j = v.size()-1;

        while(i >= 0 && j >= 0)
        {
            if(h[i] >= v[j]) {
                ans += h[i] + sumv;
                sumh -= h[i--];
            }
            else {
                ans += v[j] + sumh;
                sumv -= v[j--];
            }
        }

        return ans + sumh + sumv;
    }
};