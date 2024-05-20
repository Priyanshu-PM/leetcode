class Solution {
public:
    void findSubsets(vector<int>& nums, vector<vector<int>>& subsets, vector<int>& temp, int index)
    {
        if(index == nums.size())
        {
            subsets.push_back(temp);
            return;
        }

        temp.push_back(nums[index]);
        findSubsets(nums, subsets, temp, index + 1);
        temp.pop_back();
        findSubsets(nums, subsets, temp, index + 1);

    }
    int subsetXORSum(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        vector<vector<int>> subsets;
        vector<int> temp;
        findSubsets(nums, subsets, temp, 0);
        int ans = 0;
        for(auto it: subsets)
        {
            int sum = 0;
            for(auto ele: it)
                sum = sum ^ ele;

            ans += sum;
        }
        return ans;
    }
};