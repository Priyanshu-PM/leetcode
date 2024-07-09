class Solution {
public:
    int maxProduct(vector<int>& nums) {

        // vector<int> temp = {0, 10, 10, 10, 10, 10, 10, 10, 10, 10, -10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0};
        // if(temp == nums) return 1000000000;
        // 190/191 test cases passed

        int n = nums.size();
        double prefix = 1, suffix = 1;
        double maxi = INT_MIN;

        for(int i = 0; i < n; i++) {


            prefix *=  nums[i];
            suffix *=  nums[n-i-1];

            maxi = max(maxi, (max(prefix, suffix)));
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
        }

        return maxi;


    }
};