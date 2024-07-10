class Solution {

void findSubsets(vector<vector<int>> &ans, vector<int> &ds, int index, int n, vector<int> &nums) {
   
    ans.push_back(ds);

    for(int i = index; i < n; i++) {
        if(i != index && nums[i] == nums[i-1]) continue;
        
        ds.push_back(nums[i]);
        findSubsets(ans, ds, i+1, n, nums);
        ds.pop_back();
    }
}    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        int index = 0;
        sort(nums.begin(), nums.end());
        findSubsets(ans, ds, index, n, nums);

        return ans;

    }
};