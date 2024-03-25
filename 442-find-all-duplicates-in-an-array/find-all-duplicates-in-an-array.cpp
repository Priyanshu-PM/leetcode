class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        // T.C = O(N), S.C = O(1)
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(nums[abs(nums[i]) - 1] < 0) {
                ans.push_back(abs(nums[i]));
                continue;
            }
            nums[abs(nums[i]) - 1] *= -1;
        }
        return ans;
    }
};