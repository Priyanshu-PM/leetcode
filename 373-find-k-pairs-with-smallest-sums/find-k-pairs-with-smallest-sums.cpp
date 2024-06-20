class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue< pair<int, pair<int,int>>, 
                        vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
        
        pq.push({nums1[0] + nums2[0], {0, 0}});
        set<pair<int,int>> st;
        st.insert({0, 0});

        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> ans;
        while(!pq.empty() && k--)
        {
            auto [sum, it] = pq.top();
            pq.pop();

            int i = it.first, j = it.second;

            ans.push_back({nums1[i], nums2[j]});
            if(i + 1 < n && st.find({i+1, j}) == st.end()) {
                pq.push({nums1[i+1] + nums2[j], {i+1, j}});
                st.insert({i+1, j});
            }
            if(j + 1 < m && st.find({i, j+1}) == st.end()) {
                pq.push({nums1[i] + nums2[j+1], {i, j+1}});
                st.insert({i, j+1});
            }
        }
        return ans;
    }
};