class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();

        while(i < n && j < m)
        {
            if(nums1[i] == nums2[j])
                return nums1[i];
            
            while(i < n && nums1[i] < nums2[j]) i++;
            while(j < m && nums2[j] < nums1[i]) j++;
        }

        return -1;
    }
};