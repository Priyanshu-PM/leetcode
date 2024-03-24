class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        for(int ele: nums)
        {
            mp[ele]++;
            if(mp[ele] > 1) return ele;
        }
        return -1;
    }
};