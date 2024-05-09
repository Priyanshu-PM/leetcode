class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        priority_queue<long long> pq;
        for(int i: happiness)   pq.push(i);
        
        int minusAmount = 0;
        long long maxi = 0;
        while(k--)
        {
            int i = pq.top();
            pq.pop();
            maxi += max(0, i - minusAmount);
            minusAmount++;
        }
        
        return maxi;
    }
};