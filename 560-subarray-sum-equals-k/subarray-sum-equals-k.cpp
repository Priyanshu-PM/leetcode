class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;

        // striver prefixSum approach

        map<long long, int> mpp;
        mpp[0] = 1;
        int preSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            preSum += nums[i];

            // check if the remaining element is in the map, if yes then add the occurences of it to the count
            int remove = preSum - k;
            count += mpp[remove];
            mpp[preSum] += 1;
        }
        return count;
    }
};