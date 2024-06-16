class Solution {
public:
    
    int FirstOcc(vector<int>& nums, int size, int target) {
        
        int start = 0, end = size - 1;
        int mid = start + (end - start)/2;
        int val = -1;
        while(start <= end) {
            
            if(nums[mid] == target) {
                val = mid;
                end = mid - 1;
            }
            else if(nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
            mid = start + (end - start)/2;
            
        }
        return val;
    }
    int LastOcc(vector<int>& nums, int size, int target) {
        
        int start = 0, end = size - 1;
        int mid = start + (end - start)/2;
        int val = -1;
        while(start <= end) {
            
            if(nums[mid] == target) {
                val = mid;
                start = mid + 1;
            }
            else if(nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
            mid = start + (end - start)/2;
            
        }
        return val;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans;
        int n = nums.size();
        ans.push_back(FirstOcc(nums, n , target));
        ans.push_back(LastOcc(nums, n , target));
        
        return ans;
        
    }
};