class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < profit.size(); i++)
        {
            pq.push({profit[i], difficulty[i]});
        }

        sort(worker.rbegin(), worker.rend());   //  descending order

        int maxi = 0, i = 0, n = worker.size();
        while(i < n)
        {
            int temp = 0;
            while(!pq.empty() && pq.top().second > worker[i])   {
                pq.pop();
            }
            if(!pq.empty()) temp = pq.top().first;
            maxi += temp;
            i++;
        }
        return maxi;
    }
};