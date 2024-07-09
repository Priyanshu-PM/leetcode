class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        int n = customers.size();
        long long totalTime = 0;
        long long totalWait = 0;
        for(auto it: customers) 
        {
            int arrival = it[0], time = it[1];
            long long wait = max(totalTime + time,(long long) arrival + time) - arrival;
            totalWait += wait;
            totalTime += max((long long)arrival - totalTime,(long long) 0) + time;
        }

        double ans = (1.00000 * totalWait)/(1.00000 * n);
        return ans;
    }
};