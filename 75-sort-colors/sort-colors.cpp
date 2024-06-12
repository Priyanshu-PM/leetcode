class Solution {
public:
    void sortColors(vector<int>& nums) {
    
        int len = nums.size();
        int start = 0, mid = 0;
        int end = len-1;
        while(mid <= end)
        {
            if(nums[mid] == 0)
            {
                swap(nums[start], nums[mid]);
                mid++, start++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else if(nums[mid] == 2)
            {
                swap(nums[end], nums[mid]);
                end--;
            }
        }
        
    }
};