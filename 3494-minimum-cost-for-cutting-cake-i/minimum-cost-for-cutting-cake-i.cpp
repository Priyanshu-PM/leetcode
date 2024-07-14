class Solution {
public:
    int minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        
        sort(begin(h), end(h));
        sort(begin(v), end(v));

        int sumh = 0, sumv = 0, res = 0;
        for(int e: h)   sumh += e;
        for(int e: v)   sumv += e;

        int i = h.size()-1, j = v.size()-1;
        while(i >= 0 && j >= 0) {
            if(h[i] >= v[j]) {
                res += h[i] + sumv;
                sumh -= h[i--];
            }
            else {
                res += v[j] + sumh;
                sumv -= v[j--];
            }
        }
        return res + sumh + sumv;
    }
};