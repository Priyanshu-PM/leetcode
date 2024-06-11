class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        // int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            
            // (nums[i] == val)? count++ : nums[i - count] = nums[i];
            auto iterator = nums.begin() + i;
            
            if(nums[i] == val) {
                
                nums.erase(iterator);
                i--;
            
            }
            
        }
        
        return nums.size();
    }
};