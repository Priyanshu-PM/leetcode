class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        for(int ele: nums)
        {
            mp[ele]++;
            if(mp[ele] == 3)    mp.erase(ele);
        }
        for(auto it: mp)
            return it.first;
        return -1;
    }
};