class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        vector<int> res;
        unordered_map<int,int> mp;
        set<int> st;
        for(int ele: arr1) {
            mp[ele]++;
            st.insert(ele);
        }

        for(int i = 0; i < arr2.size(); i++)
        {
            while(mp[arr2[i]] > 0)
            {
                res.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
            st.erase(arr2[i]);
        }
        for(auto it: st) {
            while(mp[it] > 0) {
                res.push_back(it);
                mp[it]--;
            }
        }
        return res;
    }
};