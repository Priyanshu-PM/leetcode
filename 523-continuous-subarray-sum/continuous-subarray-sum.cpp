class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int mod = sum % k;
            if(mpp.find(mod) != mpp.end()) { 
                if(i - mpp[mod] > 1)
                    return true;
            }
            else
                mpp[mod] = i;
        }
        return false;
    }
};