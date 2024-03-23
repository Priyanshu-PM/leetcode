#define pi pair<int, int>

class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        for(int ele: nums)  mp[ele]++;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        for(auto it: mp)
        {
            // cout << it.first << " : " << it.second << " | ";
            pq.push({it.first, it.second});
        }
        vector<int> ans;
        while(!pq.empty() && k--)
        {
            auto it = pq.top();
            // cout << it.first << " -> " << it.second << " | ";
            ans.push_back(it.first);
            pq.pop();
        }
        return ans;
    }
};