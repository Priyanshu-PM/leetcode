class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(long long ele: nums)    pq.push(ele);
        
        long long cnt = 0;
        while(!pq.empty() && pq.top() < k)
        {
            long long num1 = pq.top();
            pq.pop();
            long long num2 = pq.top();
            pq.pop();
            long long ans = min(num1, num2)* 2 + max(num1, num2);
            pq.push(ans);
            cnt++;
        }
        
        return (int)cnt;
    }
};