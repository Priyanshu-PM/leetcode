class Solution {
public:
    int findMapped(int num, vector<int>& mapping)
    {
        int mul = 1;
        int ans = 0;
        if(num == 0)    return mapping[0];
        while(num > 0)
        {
            int digit = num % 10;
            ans = mapping[digit]*mul + ans;
            num = num / 10;
            mul = mul*10;
        }
        return ans;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;

        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++)
        {
            int mapped = findMapped(nums[i], mapping);
            v.push_back({mapped, i});
        }

        sort(v.begin(), v.end());
        for(auto i: v)
            ans.push_back(nums[i.second]);

        return ans;
    }
};