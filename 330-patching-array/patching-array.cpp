class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        
        //  try with test case
        //  [1, 4, 10], n = 20
        int len = nums.size();
        long long maxReach = 0;
        int patch = 0;
        int i = 0;
        while(maxReach < n)
        {
            if(i < nums.size() && nums[i] <= maxReach+1) {
                maxReach += nums[i];
                i++;
            }
            else {
                maxReach = maxReach + (maxReach + 1);
                patch++;
            }
        }

        return patch;
    }
};