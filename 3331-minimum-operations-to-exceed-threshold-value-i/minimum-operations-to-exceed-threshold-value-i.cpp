class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int cnt = 0;
        for(int ele: nums)
            if(ele < k) cnt++;
        return cnt;
    }
};