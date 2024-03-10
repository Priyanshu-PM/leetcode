class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        set<int> st;
        for(int ele: nums1) st.insert(ele);

        vector<int> ans;
        int n = nums2.size();
        int i = 0;
        while(i < n)
        {
            if(st.count(nums2[i]) > 0)
            {
                ans.push_back(nums2[i]);
                st.erase(nums2[i]);
            }
            i++;
        }
        return ans;
    }
};