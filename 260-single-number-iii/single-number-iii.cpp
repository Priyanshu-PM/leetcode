class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        set<int> st;
        for(int ele: nums)
        {
            if(st.count(ele) > 0)   st.erase(ele);
            else    st.insert(ele);
        }

        vector<int> ans;
        for(int ele: st)    ans.push_back(ele);
        return ans;
    }
};