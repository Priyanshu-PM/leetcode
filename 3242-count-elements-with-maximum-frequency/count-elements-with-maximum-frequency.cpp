class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int, int> mpp;
        for(int ele: nums)
            mpp[ele]++;
        
        int maxFreq = 0;
        for(auto it: mpp)
        {
            maxFreq = max(it.second, maxFreq);
        }
        int res = 0;
        for(auto it: mpp)
        {
            if(it.second == maxFreq)
                res += it.second;
        }
        return res;
    }
};