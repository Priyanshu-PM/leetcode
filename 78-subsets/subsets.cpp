class Solution {

private:
    void findSubsets(vector<int> &nums, int index, vector<vector<int>> &ans, vector<int> &ds) {
        if(index == nums.size()) {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[index]);
        findSubsets(nums, index+1, ans, ds);
        ds.pop_back();
        findSubsets(nums, index + 1, ans, ds);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        findSubsets(nums, 0, ans, ds);
        return ans;
    }
};