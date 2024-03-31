class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int minKPos = -1, maxKPos = -1;
        int culpritIndex = -1;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < minK || nums[i] > maxK)
                culpritIndex = i;

            if(nums[i] == minK) minKPos = i;
            if(nums[i] == maxK) maxKPos = i;

            int smaller = min(minKPos, maxKPos);
            int temp = smaller - culpritIndex;
            ans += (temp <= 0) ? 0 : temp;
        }
        return ans;
    }
};