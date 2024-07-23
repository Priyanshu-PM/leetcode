class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int ele: nums)  mp[ele]++;

        vector<pair<int, int>> v;
        for(auto i: mp) v.push_back({i.second, i.first});
        sort(v.begin(), v.end(), [](const pair<int,int>&a, const pair<int, int>& b) {
            if(a.first == b.first)  return a.second > b.second;
            return a.first < b.first;
        });

        vector<int> ans;
        for(auto i: v) {
            
            while(i.first-- > 0)
                ans.push_back(i.second);
        }
        return ans;
    }
};