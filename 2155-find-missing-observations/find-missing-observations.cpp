class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int numSum = 0;

        for(int i: rolls)   numSum += i;

        int m = rolls.size();
        int totalLen = n+m;

        int mumSum = mean*totalLen - numSum;

        if(n*6 < mumSum || mumSum < n)  return {};

        int rem = mumSum % n;
        int q = mumSum / n;

        vector<int> res(n, q);
        for(int i = 1; i <= rem; i++)
            res[i]++;

        return res;
    }
};