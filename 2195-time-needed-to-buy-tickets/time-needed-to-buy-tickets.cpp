class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        queue<pair<int, int>> q;    //  for storing the {tickets left, index}
        for(int i = 0; i < tickets.size(); i++)
        {
            q.push({tickets[i], i});
        }
        int time = 0;
        while(!q.empty())
        {
            auto [tickets, index] = q.front();
            q.pop();
            time++;
            if(tickets == 1)
            {
                if(index == k)  return time;
            }
            else
            {
                q.push({tickets - 1, index});
            }
        }
        return time;
    }
};