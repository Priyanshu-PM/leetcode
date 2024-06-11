class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int i = 0, j = 0;
        int prev = nums[0];
        if(n == 1)  return 1;
        while(i < n)
        {
            while(i < n && prev == nums[i])
            {
                cnt++;
                i++;
            }
            cnt = min(cnt, 2);
            while(cnt > 0) {
                cnt--;
                nums[j] = prev;
                j++;
            }
            cnt = 0;
            if(i < n)    prev = nums[i];
        }
        return j;
    }
};