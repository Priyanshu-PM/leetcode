class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        int longest = -1;
        set<int> st;
        for(int ele: nums)
        {
            if(ele < 0 && st.count(abs(ele)) > 0)
            {
                if(st.count(abs(ele)) > 0)
                    longest = max(abs(ele), longest);
                else
                    st.insert(ele);
            }
            else
            {
                if(st.count(-ele) > 0)
                    longest = max(ele, longest);
                else
                    st.insert(ele);
            }
        }
        return longest;
    }
};